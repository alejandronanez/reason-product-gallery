let getCategories = (~categories: list(Data.category)) =>
  Belt.List.map(categories, category =>
    <li key={category->Data.idGet}>
      {category->Data.nameGet->React.string}
    </li>
  )
  ->Belt.List.toArray
  ->React.array;

[@react.component]
let make = () => {
  let categories = CategoriesContext.CategoriesContext.useCategoriesState();

  switch (categories.categories) {
  | None => React.null
  | Some(categories) => <ul> {getCategories(~categories)} </ul>
  };
};