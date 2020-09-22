[@react.component]
let make = () => {
  <div> 
  {React.string("Page not found.")} 

    <Link href="/"> {React.string("Back to Home")} </Link>
  </div>;
};
