include CategoriesContext;

[@react.component]
let make = () => {
  let {selectedCategory}: CategoriesContext.state =
    CategoriesContext.useCategoriesState();

  let getSelectedProductName =
    switch (selectedCategory) {
    | Some(selectedCategoryName) =>
      Data.Category.nameGet(selectedCategoryName)
    | None => "Loading"
    };

  <React.Fragment>
    <h1 className="text-2xl font-extrabold">
      getSelectedProductName->React.string
    </h1>
    <ul>
      <li> "Item #1"->React.string </li>
      <li> "Item #2"->React.string </li>
      <li> "Item #3"->React.string </li>
      <li> "Item #4"->React.string </li>
      <li> "Item #5"->React.string </li>
    </ul>
  </React.Fragment>;
};