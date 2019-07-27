[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(array(Data.Category.category)) =
  "getCategories";

[@bs.module "../js/requests"]
external getProducts:
  (
    ~categoryId: int,
    ~minPrice: float,
    ~maxPrice: float,
    ~searchText: string
  ) =>
  Js.Promise.t(array(Data.Product.product)) =
  "getProducts";