open Constants;

open Bindings;

open Utils;

let displayRoot = () => {
  "Project Root" |> bold |> Js.log;
  packageJsonPath |> bold |> yellow |> Js.log
};
