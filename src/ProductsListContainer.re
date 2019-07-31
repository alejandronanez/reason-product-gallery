include ProductsContext;
include CategoriesContext;

[@react.component]
let make = (~categoryId) => {
  let productsDispatch = ProductsContext.useProductsDispatch();
  let {products}: ProductsContext.state = ProductsContext.useProductsState();
  let updateProductsForCategory = ProductsContext.updateProductsForCategory;

  React.useEffect1(
    () => {
      if (categoryId != CategoriesContext.invalidCategoryId) {
        updateProductsForCategory(~dispatch=productsDispatch, ~categoryId, ())
        ->ignore;
      };
      None;
    },
    [|categoryId|],
  );

  switch (products) {
  | Loading => <Loading />
  | Loaded(products) => <ProductsList products />
  | Error => <Error />
  };
};