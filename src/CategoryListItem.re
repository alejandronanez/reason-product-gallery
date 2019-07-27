let getActiveClass = (~listItem, ~selectedCategory) => {
  let baseClasses = "trans trans-fast cursor-pointer mt-2 py-1 px-2 hover:text-blue-700 hover:bg-blue-100";
  let activeClasses = "text-blue-700 bg-blue-100";

  switch (selectedCategory) {
  | Some(selectedCategory) =>
    Data.idGet(selectedCategory) === Data.idGet(listItem)
      ? baseClasses ++ " " ++ activeClasses : baseClasses
  | None => baseClasses
  };
};

[@react.component]
let make = (~listItem, ~selectedCategory, ~onClick) => {
  <li className={getActiveClass(~listItem, ~selectedCategory)} onClick>
    {listItem->Data.nameGet->React.string}
  </li>;
};