let __dirname: string = [%bs.raw {| __dirname |}];

let rootExecPath: string = [%bs.raw {| process.cwd() |}];

let test: string = "test";

let packageJsonPath = rootExecPath ++ "/package.json";

let newLine = "\n";

let tab = "\t";
