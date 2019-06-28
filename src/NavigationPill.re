[@react.component]
let make = (~children) =>
  <li
    className="trans trans-fast cursor-pointer mt-2 py-1 px-2 hover:text-blue-700 hover:bg-blue-100">
    children
  </li>;