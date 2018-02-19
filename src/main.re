open Constants;

open Bindings;

type name = string;

type command = string;

type scriptT =
  | Script(name, command);

let packageJsonPath = rootExecPath ++ "/package.json";

let scriptsJson = readFileSync(packageJsonPath, "utf8") |> Json.parse |> Json.get("scripts");

let scripts =
  switch scriptsJson {
  | Some(Object(lst)) =>
    List.map(
      (item) =>
        switch item {
        | (key, Json.String(valu)) => Script(key, valu)
        | _ => Script("none", "none")
        },
      lst
    )
  | _ => [Script("none", "none")]
  };

"Project Root" |> bold |> Js.log;

packageJsonPath |> bold |> yellow |> Js.log;

"Project Commands" |> bold |> Js.log;

List.iter(
  (item) =>
    switch item {
    | Script("none", "none") => ()
    | Script(name, command) =>
      "\t- " ++ white(name) |> Js.log;
      "\t\t" ++ yellow(command) |> Js.log
    },
  scripts
);
