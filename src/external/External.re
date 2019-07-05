[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(array(Data.category)) =
  "getCategories";