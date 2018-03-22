open Bindings;

open Constants;

let fileName = ".gitignore";

let content = "test";

type lineT =
  | Ignore(string)
  | Comment(string)
  | EmptyLine;

type sectionT = list(lineT);

type gitIgnoreT =
  | Sections(list(sectionT))
  | Single(lineT);

let string_of_lineT = (line) =>
  switch line {
  | Ignore(value) => value ++ "\n"
  | Comment(value) => {j|# $value\n|j}
  | EmptyLine => "\n"
  };

let nodeIgnore = [Comment("Dependency directories"), Ignore("node_modules/")];

let vimIgnore = [
  Comment("vim swap"),
  Ignore("*.swp"),
  Ignore(".*.*.sw[a-z]"),
  Ignore("[._]*.s[a-w][a-z]"),
  Ignore("[._]s[a-w][a-z]"),
  Ignore("*.swo"),
  Ignore("*~/")
];

let logsIgnore = [
  Comment("Logs"),
  Ignore("*.log"),
  Ignore("logs"),
  Ignore("npm-debug.log*"),
  Ignore("yarn-debug.log*"),
  Ignore("yarn-error.log*")
];

let distDirectories = [
  Comment("Common output dirs"),
  Ignore("out"),
  Ignore("build"),
  Ignore("lib"),
  Ignore("dist")
];

let ignoreAll = Sections([nodeIgnore, vimIgnore, logsIgnore]);

let ignoreSection = (section) =>
  section |> List.map(string_of_lineT) |> List.fold_left(Utils.joinStrings, "");

let allIgnoreed =
  (
    switch ignoreAll {
    | Sections(lines) => List.map(ignoreSection, lines)
    | Single(line) => [string_of_lineT(line)]
    }
  )
  |> List.fold_left(Utils.joinWithNewLine, "");

let filePath = pathJoin(rootExecPath, fileName);

filePath |> Js.log;

writeFileSync(filePath, allIgnoreed);
