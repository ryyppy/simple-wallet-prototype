// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var React = require("react");
var Button = require("../components/Button.js");

function MainLayout(Props) {
  var children = Props.children;
  return React.createElement("div", {
              className: "w-full bg-grey-10"
            }, React.createElement("div", {
                  className: "w-full bg-white"
                }, React.createElement("div", {
                      className: "flex items-center justify-end max-w-6xl w-full bg-white h-12"
                    }, React.createElement(Button.make, {
                          children: React.createElement("span", {
                                className: "flex items-center"
                              }, React.createElement(Icon.ArrowUp.make, {
                                    className: "group-hover:text-white text-white-50-tr w-4 h-auto"
                                  }), React.createElement("span", {
                                    className: "text-10 mx-1 font-bold uppercase"
                                  }, "Send"))
                        }))), React.createElement("main", {
                  className: "bg-grey-10 h-full w-full pt-16 max-w-6xl"
                }, children));
}

var make = MainLayout;

exports.make = make;
/* Icon Not a pure module */