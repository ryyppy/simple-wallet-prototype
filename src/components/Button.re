[@react.component]
let make = (~onClick=?, ~children) => {
  <button
    ?onClick className="rounded-md group bg-blue text-white inline-block h-8 px-3">
    children
  </button>;
};
