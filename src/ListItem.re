let getActiveClass = (~isActive) => {
  let baseClasses = "trans trans-fast cursor-pointer mt-2 py-1 px-2 hover:text-blue-700 hover:bg-blue-100";
  let activeClasses = "text-blue-700 bg-blue-100";

  isActive ? baseClasses ++ " " ++ activeClasses : baseClasses;
};

[@react.component]
let make = (~listItem, ~isActive, ~onClick) => {
  <li className={getActiveClass(~isActive)} onClick>
    {listItem->Data.Category.nameGet->React.string}
  </li>;
};