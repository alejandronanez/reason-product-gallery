[@react.component]
let make = (~listItem) => {
  <li
    className="trans trans-fast cursor-pointer mt-2 py-1 px-2 hover:text-blue-700 hover:bg-blue-100"
    key={listItem->Data.idGet}>
    {listItem->Data.nameGet->React.string}
  </li>;
};