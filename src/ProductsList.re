[@react.component]
let make = (~products) => {
  Js.log(products);
  <ul>
    <li> "Item #1"->React.string </li>
    <li> "Item #2"->React.string </li>
    <li> "Item #3"->React.string </li>
    <li> "Item #4"->React.string </li>
    <li> "Item #5"->React.string </li>
  </ul>;
};