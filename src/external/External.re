[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(array(Data.Category.category)) =
  "getCategories";

[@bs.deriving jsConverter]
type product = {
  categoryId: int,
  minPrice: option(float),
  maxPrice: option(float),
  searchText: option(string),
};

type productObj = {
  .
  "categoryId": int,
  "minPrice": option(float),
  "maxPrice": option(float),
  "searchText": option(string),
};

[@bs.module "../js/requests"]
external getProducts: productObj => Js.Promise.t(product) = "getProducts";