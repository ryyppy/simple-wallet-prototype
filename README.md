# Simple Wallet App

In ReScript and Electron.

**Design Mockup:**
https://www.figma.com/file/to13OFSnDid7zZOyTboyd4/Wallet-App?node-id=0%3A1

## Development

```
# In one terminal
npx rescript build -w

# In another terminal
npm start
```

An Electron window should pop up with the app running!

**Some Notes on the codebase:**
- `src/Renderer.res`: Entrypoint of the client JS app
- `src/main.js`: Still in JS; main entrypoint for the electron node process
