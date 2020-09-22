// For more context on the XMLHttpRequest thing check out:
// - https://gist.github.com/chenglou/b6cf738a5d7adbde2ee008eb93117b49
// - https://rescript-lang.org/docs/manual/latest/promise#tips--tricks
// BlockExplorer: https://tezblock.io/account/tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y

type request;
type response;

[@bs.new] external makeXMLHttpRequest: unit => request = "XMLHttpRequest";
[@bs.send]
external addEventListener: (request, string, unit => unit) => unit =
  "addEventListener";
[@bs.get] external response: request => response = "response";
[@bs.send] external open_: (request, string, string) => unit = "open";
[@bs.send] external send: request => unit = "send";
[@bs.send] external abort: request => unit = "abort";

[@bs.get] external status: request => int = "status";

let endpoint = "https://api.tzstats.com";

module Transaction = {
  // See REST Spec: https://tzstats.com/docs/api/index.html#accounts -> LIST ACCOUNT OPERATIONS
  type t = {
    row_id: float,
    receiver: option(string),
    sender: string,
    fee: float,
    volume: float,
    time: string,
  };
  [@bs.scope "JSON"] [@bs.val]
  external parseResponse: response => array(t) = "parse";

  let queryByAddress = (~address, ~onDone, ~onError, ()) => {
    let request = makeXMLHttpRequest();

    request->addEventListener("load", () => {
      onDone(request->response->parseResponse)
    });
    request->addEventListener("error", () => {onError(request->status)});

    request->open_(
      "GET",
      endpoint ++ "/explorer/account/" ++ address ++ "/operations",
    );
    request->send;

    () => {
      request->abort;
    };
  };
} /* https://api.tzstats.com/explorer/account/tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y/operation*/;

module Account = {
  // See REST Spec: https://tzstats.com/docs/api/index.html#accounts
  type t = {
    address: string,
    total_balance: float,
  };

  [@bs.scope "JSON"] [@bs.val]
  external parseResponse: response => t = "parse";

  let query = (~address, ~onDone, ~onError, ()) => {
    let request = makeXMLHttpRequest();

    request->addEventListener("load", () => {
      onDone(request->response->parseResponse)
    });
    request->addEventListener("error", () => {onError(request->status)});

    request->open_("GET", endpoint ++ "/explorer/account/" ++ address);
    request->send;

    () => {
      request->abort;
    };
  };
};
