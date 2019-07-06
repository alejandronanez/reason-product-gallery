include CategoriesContext;

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
  let categories = CategoriesContext.useCategoriesState();

  switch (categories.categories) {
  | Loaded(categories) => <ul> {getCategories(~categories)} </ul>
  | Loading => <div> "Loading"->React.string </div>
  | Error => <div> "Error"->React.string </div>
  };
};