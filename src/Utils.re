open Bindings;

open Constants;

let formattedCommand = (cmd) => {
  let coloured = yellow(cmd);
  {j|$tab$tab$coloured|j}
};

let formattedName = (name) => {
  let coloured = white(name);
  {j|$tab- $coloured|j}
};

let formattedHeader = (name) => {
  let formatted = bold(name);
  {j|$newLine$formatted|j}
};

let formattedVersion = (version) => {
  let formatted = yellow(version);
  bold({j|Version $formatted|j})
};

let formattedError = (error) => {
  let formatted = red(error);
  bold({j|Version $formatted|j})
};

let getJsonKey = (key) => readFileSync(packageJsonPath, "utf8") |> Json.parse |> Json.get(key);
