[@react.component]
let make = (~className=?, ~href: string, ~children: React.element) => {
  let onClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    ReasonReactRouter.push(href);
  };

  <a href ?className onClick> children </a>;
};