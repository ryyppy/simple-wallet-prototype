type module_
@val external module_: module_ = "module"

module HotReloader = {
  type hotFn<'props> = (. React.component<'props>) => React.component<'props>

  @module("react-hot-loader")
  external hot: (. module_) => hotFn<'props> = "hot"
}

let mockup_address2 = "tz1bDXD6nNSrebqmAnnKKwnX1QdePSMCj4MX"
let mockup_address = "tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y"

type state = {
  wallets: array<Wallet.t>,
  current: Wallet.t,
}

let mockupState = {
  let current = {
    Wallet.name: "Private Wallet",
    address: "tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y",
  }
  {
    wallets: [
      current,
      {
        Wallet.name: "Business Wallet",
        address: "tz1bDXD6nNSrebqmAnnKKwnX1QdePSMCj4MX",
      },
    ],
    current: current,
  }
}

@react.component
let make = () => {
  let url = RescriptReactRouter.useUrl()
  let route = Route.fromUrl(url)

  let (state, setState) = React.useState(_ => mockupState)

  React.useEffect0(() => {
    let watchId = RescriptReactRouter.watchUrl(url => Js.log2("Route switched to", url))
    let cleanup = () => RescriptReactRouter.unwatchUrl(watchId)
    Some(cleanup)
  })

  let content = switch route {
  | Dashboard => <Dashboard wallet=state.current />
  | Transactions => <TransactionsPage wallet=state.current />
  | Page404 => <Page404 />
  }
  let onWalletSelect = wallet => {
    Js.log2("selected wallet: ", wallet)
    setState(prev => {...prev, current: wallet})
  }
  <div className="flex">
    <div> <Sidebar wallets=state.wallets onWalletSelect /> </div> content
  </div>
}

type foo = {id: int}

let make = HotReloader.hot(. module_)(. make)
