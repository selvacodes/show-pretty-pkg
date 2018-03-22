open Utils;

type name = string;

type command = string;

type scriptT =
  | Script(name, command);

let displayScripts = () => {
  let emptyScript = Script("none", "none");
  let script_of_json = (item) =>
    switch item {
    | (key, Json.String(valu)) => Script(key, valu)
    | _ => emptyScript
    };
  let scriptsJson = getJsonKey("scripts");
  let scripts =
    switch scriptsJson {
    | Some(Object(lst)) => List.map(script_of_json, lst)
    | _ => [emptyScript]
    };
  let displaySingleCommand = (script) =>
    switch script {
    | Script("none", "none") => ()
    | Script(name, command) =>
      name |> formattedName |> Js.log;
      command |> formattedCommand |> Js.log
    };
  "Project Commands" |> formattedHeader |> Js.log;
  List.iter(displaySingleCommand, scripts)
};

let noop = () => ();

Root.displayRoot();

displayScripts();
