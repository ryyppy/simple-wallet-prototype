type version =
  | Long
  | Short;

let shorten = address => {
  let length = Js.String.length(address);
  if (length < 20) {
    address;
  } else {
    let firstPart = Js.String2.substrAtMost(address, ~from=0, ~length=8);
    let lastPart = Js.String2.substr(address, ~from=length - 8);
    firstPart ++ "..." ++ lastPart;
  };
};

[@react.component]
let make = (~version=Short, ~address: string) => {
  let str =
    switch (version) {
    | Short => shorten(address)
    | Long => address
    };

  // Only show a title when we are handling the short version,
  // otherwise it looks weird to show the same address on hover
  let title =
    switch (version) {
    | Short => Some(address)
    | Long => None
    };

  <span className="flex items-center text-grey-40 font-bold text-10" ?title>
    <button className="inline mr-2">
      <Icon.Copy className="w-3 h-3" />
    </button>
    {React.string(str)}
  </span>;
};
