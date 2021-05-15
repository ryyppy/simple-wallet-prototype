// Instructions on how to inline SVG images:
// - Open svg in text editor
// - Go to https://react-svgr.com/playground/?expandProps=none
// - Paste svg in there
// - Take the converted JSX and paste it in its own component module
// - Add stroke-current / fill-current as className to inherit text-color
// - Add className as prop and append it to the other className content
// - Convert all width / height numbers to a string
// - When it type-checks, drop the component in and see if it renders
// - Sometimes it's worth simplifying the markup a bit afterwards

module Clipboard = {
  @react.component
  let make = (~className: string="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path d="M16 4h2a2 2 0 012 2v14a2 2 0 01-2 2H6a2 2 0 01-2-2V6a2 2 0 012-2h2" />
      <rect x="8" y="2" width="8" height="4" rx="1" ry="1" />
    </svg>
}

module ArrowUp = {
  @react.component
  let make = (~className: string="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path d="M12 19V5M5 12l7-7 7 7" />
    </svg>
}

module ArrowDown = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path d="M12 5v14M19 12l-7 7-7-7" />
    </svg>
}

module UpCircle = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <circle cx="12" cy="12" r="10" /> <path d="M16 12l-4-4-4 4M12 16V8" />
    </svg>
}

module UpDownArrow = {
  @react.component
  let make = (~className="") =>
    <svg width="18" height="10" viewBox="0 0 18 10" fill="none">
      <path
        d="M4.203 8.595V1.688M.75 5.141l3.453-3.453 3.454 3.453M13.796 1.688v6.907M17.25 5.141l-3.454 3.454-3.453-3.454"
        strokeWidth="1.5"
        strokeLinecap="round"
        strokeLinejoin="round"
        className={"stroke-current " ++ className}
      />
    </svg>
}

module Plus = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current" ++ className}>
      <path d="M12 5v14M5 12h14" />
    </svg>
}

module Copy = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <rect x="9" y="9" width="13" height="13" rx="2" ry="2" />
      <path d="M5 15H4a2 2 0 01-2-2V4a2 2 0 012-2h9a2 2 0 012 2v1" />
    </svg>
}

module Burger = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path d="M3 12h18M3 6h18M3 18h18" />
    </svg>
}

module VerticalDots = {
  @react.component
  let make = (~className="") =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      stroke="currentColor"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <circle cx="12" cy="12" r="1" />
      <circle cx="12" cy="5" r="1" />
      <circle cx="12" cy="19" r="1" />
    </svg>
}

module Wallet = {
  @react.component
  let make = (~className="") =>
    <svg
      height="512"
      className={"fill-current " ++ className}
      viewBox="0 0 512.007 512.007"
      width="512">
      <path
        d="M466.004 176.007h-82V36.033c0-12.568-6.383-24.016-17.074-30.624-10.689-6.607-23.783-7.197-35.025-1.576a17.33 17.33 0 00-.428.222L34.697 163.777a65.863 65.863 0 00-34.693 58.07v244.16c0 25.364 20.636 46 46 46h420c25.364 0 46-20.636 46-46v-244c0-25.364-20.636-46-46-46zM346.355 32.388c1.587-.73 2.911-.276 3.751.243.866.535 1.897 1.56 1.897 3.403v139.974H79.496zm133.649 433.619c0 7.72-6.28 14-14 14h-420c-7.72 0-14-6.28-14-14v-244c0-7.72 6.28-14 14-14h420c7.72 0 14 6.28 14 14z"
      />
      <path
        d="M416.004 376.007c-17.645 0-32-14.355-32-32s14.355-32 32-32 32 14.355 32 32-14.356 32-32 32zm0-32l.001.021z"
      />
    </svg>
}
