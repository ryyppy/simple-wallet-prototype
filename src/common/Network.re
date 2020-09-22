type t =
  | Mainnet
  | Testnet;

let toString = t =>
  switch (t) {
  | Mainnet => "mainnet"
  | Testnet => "testnet"
  };
