type route =
  | Dashboard
  | Transactions
  | Page404

let fromUrl = (url: ReasonReactRouter.url) =>
  switch url.hash {
  | "dashboard" => Dashboard
  | "transactions" => Transactions
  | _ => Dashboard
  }

let toHref = route =>
  switch route {
  | Dashboard => "#dashboard"
  | Transactions => "#transactions"
  | Page404 => "#not-found"
  }
