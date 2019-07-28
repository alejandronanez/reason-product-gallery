include ProductsContext;
include CategoriesContext;

[@react.component]
let make = (~categoryId) => {
  let productsDispatch = ProductsContext.useProductsDispatch();
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

  <ProductsList products="Something" />;
};