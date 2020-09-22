// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';


function fromUrl(url) {
  var match = url.hash;
  switch (match) {
    case "dashboard" :
        return /* Dashboard */0;
    case "transactions" :
        return /* Transactions */1;
    default:
      return /* Dashboard */0;
  }
}

function toHref(route) {
  switch (route) {
    case /* Dashboard */0 :
        return "#dashboard";
    case /* Transactions */1 :
        return "#transactions";
    case /* Page404 */2 :
        return "#not-found";
    
  }
}

exports.fromUrl = fromUrl;
exports.toHref = toHref;
/* No side effect */