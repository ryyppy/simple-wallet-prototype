%%raw("import './css/main.css'")

// This is the entry point for our webclient

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(<App />, root)
| None => () // do nothing
}
