[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(array(Data.Category.category)) =
  "getCategories";

[@bs.module "../js/requests"]
external getProducts:
  Data.Product.productInputObj => Js.Promise.t(array(Data.Product.product)) =
  "getProducts";