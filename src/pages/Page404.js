// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Link = require("../components/Link.js");
var React = require("react");

function Page404(Props) {
  return React.createElement("div", undefined, "Page not found.", React.createElement(Link.make, {
                  href: "/",
                  children: "Back to Home"
                }));
}

var make = Page404;

exports.make = make;
/* Link Not a pure module */
