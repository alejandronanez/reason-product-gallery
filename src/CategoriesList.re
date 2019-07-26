include CategoriesContext;

[@react.component]
let make = () => {
  let {categories: listItems}: CategoriesContext.state =
    CategoriesContext.useCategoriesState();

  switch (listItems) {
  | Loaded(listItems) => <ul> <CategoriesListItem listItems /> </ul>
  | Loading => <div> "Loading categories"->React.string </div>
  | Error => <div> "Error loading categories"->React.string </div>
  };
};