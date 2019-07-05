[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(list(Data.category)) =
  "getCategories";