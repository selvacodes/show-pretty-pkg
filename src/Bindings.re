[@bs.val] [@bs.module "chalk"] external white : string => string = "";

[@bs.val] [@bs.module "chalk"] external green : string => string = "";

[@bs.val] [@bs.module "chalk"] external red : string => string = "";

[@bs.val] [@bs.module "chalk"] external gray : string => string = "";

[@bs.val] [@bs.module "chalk"] external yellow : string => string = "";

[@bs.val] [@bs.module "chalk"] external blue : string => string = "";

[@bs.val] [@bs.module "chalk"] external bold : string => string = "";

[@bs.val] [@bs.module "fs"] external readFileSync : (string, string) => string = "readFileSync";
/*type t =*/
/*| String(string)*/
/*| Number(float)*/
/*| Array(list(t))*/
/*| Object(list((string, t)))*/
/*| True*/
/*| False*/
/*| Null;*/
