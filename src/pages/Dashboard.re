module AccountOverview = {
  [@react.component]
  let make =
      (
        ~avatarSrc="/static/img/default-avatar.png",
        ~walletName="Bruno's Wallet",
        ~account: TezStats.Account.t,
      ) => {
    let {TezStats.Account.total_balance, address} = account;
    let intl = IntlNumberFormat.make(~lang=`en);

    let amount = intl->IntlNumberFormat.format(total_balance) ++ {j| ꜩ|j};
    <div ariaLabel="button" className="flex rounded-lg bg-white px-6 py-6">
      <img className="w-32 h-32 rounded-full" src=avatarSrc />
      <div className="ml-4 mt-4">
        <h2 className="text-16 font-bold text-blue-90">
          {React.string(walletName)}
        </h2>
        <TzAddress version=TzAddress.Long address />
        <div className="text-36 font-bold text-blue-90 mt-3">
          {React.string(amount)}
        </div>
      </div>
    </div>;
  };
};

module AccountLoading = {
  [@react.component]
  let make = () => {
    <div> {React.string("Loading")} </div>;
  };
};

type state =
  | Init
  | Loading
  | Success(TezStats.Account.t)
  | Failed(string);

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
        TezStats.Account.query(
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

  let accountOverview =
    switch (state) {
    | Init
    | Loading => <AccountLoading />
    | Success(account) => <AccountOverview account walletName={wallet.name} />
    | Failed(err) =>
      <div>
        {React.string("Could not load account due to a problem: " ++ err)}
      </div>
    };

  <MainLayout>
    <div className="flex w-full justify-center">
      <div
        className="w-full" style={ReactDOMStyle.make(~maxWidth="34rem", ())}>
        accountOverview
      </div>
    </div>
  </MainLayout>;
};
