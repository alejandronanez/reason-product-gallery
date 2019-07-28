include CategoriesContext;

[@react.component]
let make = () => {
  let {selectedCategory}: CategoriesContext.state =
    CategoriesContext.useCategoriesState();

  let selectedCategoryName =
    switch (selectedCategory) {
    | Some(selectedCategoryName) =>
      Data.Category.nameGet(selectedCategoryName)
    | None => "Loading"
    };

  let selectedCategoryId =
    switch (selectedCategory) {
    | Some(selectedCategoryName) => Data.Category.idGet(selectedCategoryName)
    | None => CategoriesContext.invalidCategoryId
    };

  <React.Fragment>
    <h1 className="text-2xl font-extrabold">
      selectedCategoryName->React.string
    </h1>
    <ProductsListContainer categoryId=selectedCategoryId />
  </React.Fragment>;
};