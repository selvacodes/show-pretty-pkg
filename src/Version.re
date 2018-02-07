open Constants;

open Bindings;

let version =
  readFileSync(rootExecPath ++ "/package.json", "utf8") |> Json.parse |> Json.get("version");

switch version {
| Some(Json.String(valu)) => bold("Version") ++ " " ++ yellow(valu) |> bold |> Js.log
| None => "\t- " ++ white("No Version Found") |> Js.log
| _ => ()
};
