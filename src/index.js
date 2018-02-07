#!/usr/bin/env node

var argv = require("minimist")(process.argv.slice(2))

const tagsNeeded = Object.keys(argv)

if (tagsNeeded.length === 1) {
  require("./main.js")
} else {
  tagsNeeded.forEach(tag => {
    switch (tag) {
      case "scripts":
        require("./main.js")
        break
      case "version":
        require("./Version.js")
        break
    }
  })
}
