let __dirname: string = [%bs.raw {| __dirname |}];

let rootExecPath: string = [%bs.raw {| process.cwd() |}];
