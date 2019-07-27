include CategoriesContext;

let getIsActive = (~selectedItem, ~currentItem) => {
  switch (selectedItem) {
  | Some(selectedItem) =>
    Data.idGet(selectedItem) === Data.idGet(currentItem)
  | None => false
  };
};

[@react.component]
let make = () => {
  let {categories: listItems, selectedCategory}: CategoriesContext.state =
    CategoriesContext.useCategoriesState();
  let categoriesDispatch = CategoriesContext.useCategoriesDispatch();

  let handleClick = (listItem, e) => {
    ReactEvent.Synthetic.preventDefault(e);

    categoriesDispatch(CategoriesContext.SelectCategory(listItem));
  };

  switch (listItems) {
  | Loaded(listItems) =>
    <ul>
      {listItems
       ->Belt.List.map(listItem =>
           <ListItem
             key={listItem->Data.idGet}
             listItem
             isActive={getIsActive(
               ~selectedItem=selectedCategory,
               ~currentItem=listItem,
             )}
             onClick={handleClick(listItem)}
           />
         )
       ->Belt.List.toArray
       ->React.array}
    </ul>
  | Loading => <div> "Loading categories"->React.string </div>
  | Error => <div> "Error loading categories"->React.string </div>
  };
};