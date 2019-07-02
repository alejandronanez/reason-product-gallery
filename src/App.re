module CounterDisplay = {
  [@react.component]
  let make = () => {
    let count = CategoriesContext.useCountState();
    <div> {count.count->string_of_int->React.string} </div>;
  };
};

module CounterButton = {
  [@react.component]
  let make = () => {
    let dispatch = CategoriesContext.useCountDispatch();
    <button onClick={_ => dispatch(CategoriesContext.Increment)}>
      "Count"->React.string
    </button>;
  };
};

[@react.component]
let make = () => {
  <div>
    <div className="flex bg-gray-800 text-gray-100">
      <SectionContainer> <Navigation /> </SectionContainer>
    </div>
    <CounterDisplay />
    <CounterButton />
    <SectionContainer>
      <section className="flex mt-3">
        <aside className="md:w-1/3">
          <nav>
            <h2 className="text-xl font-extrabold">
              "All categories"->React.string
            </h2>
            <ul>
              <NavigationPill> "Item one"->React.string </NavigationPill>
              <NavigationPill> "Item two"->React.string </NavigationPill>
              <NavigationPill> "Item three"->React.string </NavigationPill>
            </ul>
          </nav>
          <nav>
            <h2 className="text-xl font-extrabold mt-3">
              "Filters"->React.string
            </h2>
            <ul>
              <NavigationPill> "Min"->React.string </NavigationPill>
              <NavigationPill> "Max"->React.string </NavigationPill>
            </ul>
          </nav>
        </aside>
        <main className="md:w-2/3">
          <h1 className="text-2xl font-extrabold">
            "Selected section"->React.string
          </h1>
          <ul>
            <li> "Item #1"->React.string </li>
            <li> "Item #2"->React.string </li>
            <li> "Item #3"->React.string </li>
            <li> "Item #4"->React.string </li>
            <li> "Item #5"->React.string </li>
          </ul>
        </main>
      </section>
    </SectionContainer>
  </div>;
};