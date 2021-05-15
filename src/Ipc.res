type event
type command = string

module IpcRenderer = {
  type t
  @module("electron") external ipcMain: t = "ipcMain"
}

module IpcMain = {
  type t

  @module("electron") external ipcRenderer: t = "ipcRenderer"

  @send
  external handle: (t, command, @uncurry (event, 'arg) => unit) => unit = "handle"
}

{
  open IpcMain
  ipcRenderer->handle("perform-action", (evt, arg) => {
    Js.log2("event", evt)
    Js.log2("arg", arg)
  })
}
