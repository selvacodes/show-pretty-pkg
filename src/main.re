open Constants;

open Bindings;

open Utils;

type name = string;

type command = string;

type scriptT =
  | Script(name, command);

let displayScripts = () => {
  let scriptsJson = getJsonKey("scripts");
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
  "Project Commands" |> formattedHeader |> Js.log;
  List.iter(
    (item) =>
      switch item {
      | Script("none", "none") => ()
      | Script(name, command) =>
        name |> formattedName |> Js.log;
        command |> formattedCommand |> Js.log
      },
    scripts
  )
};

let noop = () => ();

Root.displayRoot();

displayScripts();
