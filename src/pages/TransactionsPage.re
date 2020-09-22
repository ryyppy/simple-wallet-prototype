type state =
  | Init
  | Loading
  | Success(array(TezStats.Transaction.t))
  | Failed(string);

module TransactionHistory = {
  let styledAmount = (~gotPaid, volume) => {
    let className = gotPaid ? "text-green" : "text-red";
    let amount =
      gotPaid
        ? Belt.Float.toString(volume) : "- " ++ Belt.Float.toString(volume);
    <span className> {React.string(amount)} </span>;
  };

  [@react.component]
  let make = (~wallet: Wallet.t, ~data: array(TezStats.Transaction.t)) => {
    let {Wallet.address} = wallet;
    let items =
      Belt.Array.map(
        data,
        tr => {
          let {TezStats.Transaction.row_id, sender, receiver, volume} = tr;
          switch (receiver) {
          | Some(receiver) =>
            if (receiver === address || sender === address) {
              let gotPaid = receiver === address;

              let arrowColors =
                gotPaid
                  ? "text-green bg-green-light" : "text-red bg-red-10-tr";

              let arrow =
                <span
                  className={
                    arrowColors ++ " inline-block rounded-lg py-2 px-2"
                  }>
                  {gotPaid ? <Icon.ArrowUp /> : <Icon.ArrowDown />}
                </span>;

              let className = "border-t border-grey-10 py-3 pl-4 text-14";

              <tr key={Belt.Float.toString(row_id)}>
                <td className> arrow </td>
                <td className> <TzAddress address=sender /> </td>
                <td className> <TzAddress address=receiver /> </td>
                <td className> {styledAmount(~gotPaid, volume)} </td>
              </tr>;
            } else {
              React.null;
            }
          | None => React.null
          };
        },
      );

    let thClass = "text-left pl-4";
    <div className="bg-white rounded-lg px-6 pt-3 pb-6">
      <h1 className="text-16 font-bold mb-6">
        {React.string("Transaction History for " ++ wallet.name)}
      </h1>
      <table className="w-full">
        <thead>
          <tr className="text-10 uppercase font-bold">
            <th className=thClass> <Icon.UpDownArrow /> </th>
            <th className=thClass> {React.string("Sender")} </th>
            <th className=thClass> {React.string("Receiver")} </th>
            <th className=thClass>
              {React.string("Amount " ++ {j|ꜩ|j})}
            </th>
          </tr>
        </thead>
        <tbody> {React.array(items)} </tbody>
      </table>
    </div>;
  };
};

module Placeholder = {
  [@react.component]
  let make = () => {
    let thClass = "text-left pl-4";

    let mockupRows =
      Belt.Array.mapWithIndex([|"w-1/4", "w-2/3", "w-4/6"|], (i, width) => {
        <tr key={Belt.Int.toString(i)}>
          <td colSpan=4 className="py-3 pl-4">
            <div
              className={width ++ " rounded-lg animate-pulse h-6 bg-grey-40"}
            />
          </td>
        </tr>
      });

    <div className="bg-white rounded-lg px-6 pt-3 pb-6">
      <h1 className="text-16 font-bold mb-6">
        {React.string("Transaction History")}
      </h1>
      <table className="w-full">
        <thead>
          <tr className="text-10 uppercase font-bold">
            <th className=thClass> <Icon.UpDownArrow /> </th>
            <th className=thClass> {React.string("Sender")} </th>
            <th className=thClass> {React.string("Receiver")} </th>
            <th className=thClass> {React.string("Amount")} </th>
          </tr>
        </thead>
        <tbody> {React.array(mockupRows)} </tbody>
      </table>
    </div>;
  };
};

[@react.component]
let make = (~wallet: Wallet.t) => {
  let (state, setState) = React.useState(_ => Init);
  React.useEffect1(
    () => {
      let onDone = data => {
        setState(_ => Success(data));
      };

      let onError = code => {
        setState(_ => Failed("Error code " ++ Belt.Int.toString(code)));
      };

      let cancel =
        TezStats.Transaction.queryByAddress(
          ~address=wallet.address,
          ~onDone,
          ~onError,
          (),
        );

      setState(_ => Loading);

      Some(() => cancel());
    },
    [|wallet.address|],
  );

  let content =
    switch (state) {
    | Init
    | Loading => <Placeholder />
    | Success(data) => <TransactionHistory wallet data />
    | Failed(err) => React.string("Could not load data: " ++ err)
    };

  <MainLayout>
    <div className="flex justify-center w-full px-8">
      <div
        className="w-full" style={ReactDOMStyle.make(~maxWidth="54rem", ())}>
        content
      </div>
    </div>
  </MainLayout>;
};
