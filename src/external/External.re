type category = CategoriesContext.CategoriesContext.category;

[@bs.module "../js/requests"]
external getCategories: unit => Js.Promise.t(category) = "getCategories";