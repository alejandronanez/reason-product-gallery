[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(array(Data.Category.category)) =
  "getCategories";