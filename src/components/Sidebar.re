module MyAccounts = {
  [@react.component]
  let make = (~wallets: array(Wallet.t), ~onWalletSelect=?) => {
    let items =
      Belt.Array.map(
        wallets,
        wallet => {
          let onClick = evt => {
            ReactEvent.Mouse.preventDefault(evt);
            Belt.Option.forEach(onWalletSelect, fn => fn(wallet));
          };
          <li onClick key={wallet.address} className="py-2 text-white-90-tr">
            <a onClick className="cursor-pointer hover:text-white">
              {React.string(wallet.name)}
            </a>
          </li>;
        },
      );

    <div>
      <h2 className="text-10 font-bold text-white-50-tr uppercase">
        {React.string("My Wallets")}
      </h2>
      <ul className="text-14 text-white-90-tr"> {React.array(items)} </ul>
    </div>;
  };
};

module MyPages = {
  [@react.component]
  let make = () => {
    let url = ReasonReactRouter.useUrl();
    let route = Route.fromUrl(url);

    let pages = [|
      ("Dashboard", Route.Dashboard),
      ("Transactions", Route.Transactions),
    |];

    let items =
      Belt.Array.map(
        pages,
        ((text, target)) => {
          let active = route === target ? "bg-blue" : "";
          let href = Route.toHref(target);
          <li key=href className={active ++ " pl-8 py-2 text-white-90-tr"}>
            <Link href> {React.string(text)} </Link>
          </li>;
        },
      );

    <div>
      <h2 className="pl-8 text-10 font-bold text-white-50-tr uppercase">
        {React.string("Pages")}
      </h2>
      <ul className="text-14 text-white-90-tr"> {React.array(items)} </ul>
    </div>;
  };
};

module ConnectedBox = {
  type status =
    | Connected(Network.t)
    | Disconnected(Network.t);

  [@react.component]
  let make = (~status: status) => {
    let (color, networkName) =
      switch (status) {
      | Connected(network) => ("bg-green", Network.toString(network))
      | Disconnected(network) => ("bg-red", Network.toString(network))
      };

    <div className="bg-white-10-tr">
      <div className={"w-4 h-4 " ++ color} />
      {React.string(networkName)}
    </div>;
  };
};

module BurgerButton = {
  [@react.component]
  let make = (~onClick) => {
    <button onClick className="group">
      <Icon.Burger className="group-hover:text-white text-white-50-tr w-8" />
    </button>;
  };
};

module FullSidebar = {
  [@react.component]
  let make = (~onBurgerButtonClick, ~wallets, ~onWalletSelect) => {
    <div className="h-full min-h-screen bg-blue-dark">
      <div
        className="h-12 w-full justify-between flex items-center border-b border-1 border-white-20-tr pl-8 pr-4"
        style={ReactDOMStyle.make(~minWidth="16.5rem", ())}>
        <span className="flex items-center">
          <Icon.Wallet className="text-blue w-6 h-auto" />
          <span className="cursor-default text-16 text-white-90-tr ml-4">
            {React.string("Wallet App")}
          </span>
        </span>
        <BurgerButton onClick=onBurgerButtonClick />
      </div>
      <div className="pl-8 pr-4 pt-12">
        <MyAccounts wallets onWalletSelect />
      </div>
      <div className="pt-12"> <MyPages /> </div>
    </div>;
  };
};

module CollapsedSidebar = {
  [@react.component]
  let make = (~onBurgerButtonClick) => {
    <div className="w-12 bg-blue-dark h-screen">
      <div className="h-12 justify-center flex items-center w-full">
        <BurgerButton onClick=onBurgerButtonClick />
      </div>
    </div>;
  };
};

[@react.component]
let make = (~wallets: array(Wallet.t), ~onWalletSelect: Wallet.t => unit) => {
  let (collapsed, setCollapsed) = React.useState(_ => false);

  let onBurgerButtonClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    setCollapsed(prev => !prev);
  };

  collapsed
    ? <CollapsedSidebar onBurgerButtonClick />
    : <FullSidebar onBurgerButtonClick wallets onWalletSelect />;
};
