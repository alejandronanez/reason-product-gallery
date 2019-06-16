[@react.component]
let make = () => {
  <div>
    <div> <nav> "I am the navigation"->React.string </nav> </div>
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
      <section>
        <h1> "Selected section"->React.string </h1>
        <ul>
          <li> "Item #1"->React.string </li>
          <li> "Item #2"->React.string </li>
          <li> "Item #3"->React.string </li>
          <li> "Item #4"->React.string </li>
          <li> "Item #5"->React.string </li>
        </ul>
      </section>
    </section>
  </div>;
};