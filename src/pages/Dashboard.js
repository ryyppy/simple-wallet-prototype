// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("rescript/lib/js/curry.js");
var React = require("react");
var TezStats = require("../common/TezStats.js");
var TzAddress = require("../components/TzAddress.js");
var MainLayout = require("../layouts/MainLayout.js");

function Dashboard$AccountOverview(Props) {
  var avatarSrcOpt = Props.avatarSrc;
  var walletNameOpt = Props.walletName;
  var account = Props.account;
  var avatarSrc = avatarSrcOpt !== undefined ? avatarSrcOpt : "/static/img/default-avatar.png";
  var walletName = walletNameOpt !== undefined ? walletNameOpt : "Bruno's Wallet";
  var intl = new (Intl.NumberFormat)("en-US");
  var amount = intl.format(account.total_balance) + " ꜩ";
  return React.createElement("div", {
              "aria-label": "button",
              className: "flex rounded-lg bg-white px-6 py-6"
            }, React.createElement("img", {
                  className: "w-32 h-32 rounded-full",
                  src: avatarSrc
                }), React.createElement("div", {
                  className: "ml-4 mt-4"
                }, React.createElement("h2", {
                      className: "text-16 font-bold text-blue-90"
                    }, walletName), React.createElement(TzAddress.make, {
                      version: /* Long */0,
                      address: account.address
                    }), React.createElement("div", {
                      className: "text-36 font-bold text-blue-90 mt-3"
                    }, amount)));
}

var AccountOverview = {
  make: Dashboard$AccountOverview
};

function Dashboard$AccountLoading(Props) {
  return React.createElement("div", undefined, "Loading");
}

var AccountLoading = {
  make: Dashboard$AccountLoading
};

function Dashboard(Props) {
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
          var cancel = TezStats.Account.query(wallet.address, onDone, onError, undefined);
          Curry._1(setState, (function (param) {
                  return /* Loading */1;
                }));
          return (function (param) {
                    return Curry._1(cancel, undefined);
                  });
        }), [wallet.address]);
  var accountOverview;
  accountOverview = typeof state === "number" ? (
      state === /* Init */0 ? React.createElement(Dashboard$AccountLoading, {}) : React.createElement(Dashboard$AccountLoading, {})
    ) : (
      state.TAG === /* Success */0 ? React.createElement(Dashboard$AccountOverview, {
              walletName: wallet.name,
              account: state._0
            }) : React.createElement("div", undefined, "Could not load account due to a problem: " + state._0)
    );
  return React.createElement(MainLayout.make, {
              children: React.createElement("div", {
                    className: "flex w-full justify-center"
                  }, React.createElement("div", {
                        className: "w-full",
                        style: {
                          maxWidth: "34rem"
                        }
                      }, accountOverview))
            });
}

var make = Dashboard;

exports.AccountOverview = AccountOverview;
exports.AccountLoading = AccountLoading;
exports.make = make;
/* react Not a pure module */
