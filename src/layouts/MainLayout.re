[@react.component]
let make = (~children) => {
  <div className="w-full bg-grey-10">
    <div className="w-full bg-white">
      <div
        className="flex items-center justify-end max-w-6xl w-full bg-white h-12">
        <Button>
          <span className="flex items-center">
            <Icon.ArrowUp
              className="group-hover:text-white text-white-50-tr w-4 h-auto"
            />
            <span className="text-10 mx-1 font-bold uppercase">
              {React.string("Send")}
            </span>
          </span>
        </Button>
      </div>
    </div>
    <main className="bg-grey-10 h-full w-full pt-16 max-w-6xl">
      children
    </main>
  </div>;
};
