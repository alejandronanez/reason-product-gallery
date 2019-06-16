[@react.component]
let make = () => {
  <div>
    <div className="flex bg-gray-800 text-gray-100">
      <SectionContainer> <Navigation /> </SectionContainer>
    </div>
    <SectionContainer>
      <section>
        <aside>
          <nav>
            <h2> "All categories"->React.string </h2>
            <ul>
              <li> "Item one"->React.string </li>
              <li> "Item two"->React.string </li>
              <li> "Item three"->React.string </li>
            </ul>
          </nav>
          <nav>
            <h2> "Filters"->React.string </h2>
            <ul>
              <li> "Min"->React.string </li>
              <li> "Max"->React.string </li>
            </ul>
          </nav>
        </aside>
        <main>
          <h1> "Selected section"->React.string </h1>
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