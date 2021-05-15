// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var Curry = require("rescript/lib/js/curry.js");
var React = require("react");
var TezStats = require("../common/TezStats.js");
var TzAddress = require("../components/TzAddress.js");
var Belt_Array = require("rescript/lib/js/belt_Array.js");
var MainLayout = require("../layouts/MainLayout.js");

function styledAmount(gotPaid, volume) {
  var className = gotPaid ? "text-green" : "text-red";
  var amount = gotPaid ? String(volume) : "- " + String(volume);
  return React.createElement("span", {
              className: className
            }, amount);
}

function TransactionsPage$TransactionHistory(Props) {
  var wallet = Props.wallet;
  var data = Props.data;
  var address = wallet.address;
  var items = Belt_Array.map(data, (function (tr) {
          var receiver = tr.receiver;
          if (receiver === undefined) {
            return null;
          }
          var sender = tr.sender;
          if (!(receiver === address || sender === address)) {
            return null;
          }
          var gotPaid = receiver === address;
          var arrowColors = gotPaid ? "text-green bg-green-light" : "text-red bg-red-10-tr";
          var arrow = React.createElement("span", {
                className: arrowColors + " inline-block rounded-lg py-2 px-2"
              }, gotPaid ? React.createElement(Icon.ArrowUp.make, {}) : React.createElement(Icon.ArrowDown.make, {}));
          var className = "border-t border-grey-10 py-3 pl-4 text-14";
          return React.createElement("tr", {
                      key: String(tr.row_id)
                    }, React.createElement("td", {
                          className: className
                        }, arrow), React.createElement("td", {
                          className: className
                        }, React.createElement(TzAddress.make, {
                              address: sender
                            })), React.createElement("td", {
                          className: className
                        }, React.createElement(TzAddress.make, {
                              address: receiver
                            })), React.createElement("td", {
                          className: className
                        }, styledAmount(gotPaid, tr.volume)));
        }));
  var thClass = "text-left pl-4";
  return React.createElement("div", {
              className: "bg-white rounded-lg px-6 pt-3 pb-6"
            }, React.createElement("h1", {
                  className: "text-16 font-bold mb-6"
                }, "Transaction History for " + wallet.name), React.createElement("table", {
                  className: "w-full"
                }, React.createElement("thead", undefined, React.createElement("tr", {
                          className: "text-10 uppercase font-bold"
                        }, React.createElement("th", {
                              className: thClass
                            }, React.createElement(Icon.UpDownArrow.make, {})), React.createElement("th", {
                              className: thClass
                            }, "Sender"), React.createElement("th", {
                              className: thClass
                            }, "Receiver"), React.createElement("th", {
                              className: thClass
                            }, "Amount " + "ꜩ"))), React.createElement("tbody", undefined, items)));
}

var TransactionHistory = {
  styledAmount: styledAmount,
  make: TransactionsPage$TransactionHistory
};

function TransactionsPage$Placeholder(Props) {
  var thClass = "text-left pl-4";
  var mockupRows = Belt_Array.mapWithIndex([
        "w-1/4",
        "w-2/3",
        "w-4/6"
      ], (function (i, width) {
          return React.createElement("tr", {
                      key: String(i)
                    }, React.createElement("td", {
                          className: "py-3 pl-4",
                          colSpan: 4
                        }, React.createElement("div", {
                              className: width + " rounded-lg animate-pulse h-6 bg-grey-40"
                            })));
        }));
  return React.createElement("div", {
              className: "bg-white rounded-lg px-6 pt-3 pb-6"
            }, React.createElement("h1", {
                  className: "text-16 font-bold mb-6"
                }, "Transaction History"), React.createElement("table", {
                  className: "w-full"
                }, React.createElement("thead", undefined, React.createElement("tr", {
                          className: "text-10 uppercase font-bold"
                        }, React.createElement("th", {
                              className: thClass
                            }, React.createElement(Icon.UpDownArrow.make, {})), React.createElement("th", {
                              className: thClass
                            }, "Sender"), React.createElement("th", {
                              className: thClass
                            }, "Receiver"), React.createElement("th", {
                              className: thClass
                            }, "Amount"))), React.createElement("tbody", undefined, mockupRows)));
}

var Placeholder = {
  make: TransactionsPage$Placeholder
};

function TransactionsPage(Props) {
  var wallet = Props.wallet;
  var match = React.useState(function () {
        return /* Init */0;
      });
  var setState = match[1];
  var state = match[0];
  React.useEffect((function () {
          var onDone = function (data) {
            return Curry._1(setState, (function (param) {
                          return {
                                  TAG: /* Success */0,
                                  _0: data
                                };
                        }));
          };
          var onError = function (code) {
            return Curry._1(setState, (function (param) {
                          return {
                                  TAG: /* Failed */1,
                                  _0: "Error code " + String(code)
                                };
                        }));
          };
          var cancel = TezStats.Transaction.queryByAddress(wallet.address, onDone, onError, undefined);
          Curry._1(setState, (function (param) {
                  return /* Loading */1;
                }));
          return (function (param) {
                    return Curry._1(cancel, undefined);
                  });
        }), [wallet.address]);
  var content;
  content = typeof state === "number" ? (
      state === /* Init */0 ? React.createElement(TransactionsPage$Placeholder, {}) : React.createElement(TransactionsPage$Placeholder, {})
    ) : (
      state.TAG === /* Success */0 ? React.createElement(TransactionsPage$TransactionHistory, {
              wallet: wallet,
              data: state._0
            }) : "Could not load data: " + state._0
    );
  return React.createElement(MainLayout.make, {
              children: React.createElement("div", {
                    className: "flex justify-center w-full px-8"
                  }, React.createElement("div", {
                        className: "w-full",
                        style: {
                          maxWidth: "54rem"
                        }
                      }, content))
            });
}

var make = TransactionsPage;

exports.TransactionHistory = TransactionHistory;
exports.Placeholder = Placeholder;
exports.make = make;
/* Icon Not a pure module */
