type event;
type command = string;

module IpcRenderer = {
  type t;
  [@bs.module "electron"] external ipcMain: t = "ipcMain";
};

module IpcMain = {
  type t;

  [@bs.module "electron"] external ipcRenderer: t = "ipcRenderer";

  [@bs.send]
  external handle: (t, command, [@bs.uncurry] ((event, 'arg) => unit)) => unit =
    "handle";
};

IpcMain.(
  ipcRenderer->handle("perform-action", (evt, arg) => {
    Js.log2("event", evt);
    Js.log2("arg", arg);
  })
);