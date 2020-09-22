// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

var endpoint = "https://api.tzstats.com";

function queryByAddress(address, onDone, onError, param) {
  var request = new XMLHttpRequest();
  request.addEventListener("load", (function (param) {
          return Curry._1(onDone, JSON.parse(request.response));
        }));
  request.addEventListener("error", (function (param) {
          return Curry._1(onError, request.status);
        }));
  request.open("GET", endpoint + ("/explorer/account/" + (address + "/operations")));
  request.send();
  return function (param) {
    request.abort();
    
  };
}

var Transaction = {
  queryByAddress: queryByAddress
};

function query(address, onDone, onError, param) {
  var request = new XMLHttpRequest();
  request.addEventListener("load", (function (param) {
          return Curry._1(onDone, JSON.parse(request.response));
        }));
  request.addEventListener("error", (function (param) {
          return Curry._1(onError, request.status);
        }));
  request.open("GET", endpoint + ("/explorer/account/" + address));
  request.send();
  return function (param) {
    request.abort();
    
  };
}

var Account = {
  query: query
};

exports.endpoint = endpoint;
exports.Transaction = Transaction;
exports.Account = Account;
/* No side effect */
