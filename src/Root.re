open Constants;

open Bindings;

let displayRoot = () => {
  "Project Root" |> bold |> Js.log;
  packageJsonPath |> bold |> yellow |> Js.log
};
