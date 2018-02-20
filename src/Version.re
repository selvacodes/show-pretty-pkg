open Constants;

open Bindings;

open Utils;

let displayVersion = () => {
  let version = getJsonKey("version");
  switch version {
  | Some(Json.String(valu)) => valu |> formattedVersion |> Js.log
  | None => "\t- " ++ white("No Version Found") |> Js.log
  | _ => ()
  }
};

let noop = () => ();

displayVersion();
