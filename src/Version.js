// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Chalk               = require("chalk");
var Utils$ShowPrettyPkg = require("./Utils.js");

function displayVersion() {
  var version = Utils$ShowPrettyPkg.getJsonKey("version");
  if (version) {
    var match = version[0];
    if (typeof match === "number") {
      return /* () */0;
    } else if (match.tag) {
      return /* () */0;
    } else {
      console.log(Utils$ShowPrettyPkg.formattedVersion(match[0]));
      return /* () */0;
    }
  } else {
    console.log("\t- " + Chalk.white("No Version Found"));
    return /* () */0;
  }
}

function noop() {
  return /* () */0;
}

displayVersion(/* () */0);

exports.displayVersion = displayVersion;
exports.noop           = noop;
/*  Not a pure module */
