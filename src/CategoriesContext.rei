module CategoriesContext: {
  type action =
    | Increment
    | Decrement;
  type state = {count: int};

  let useCountState: unit => state;
  let useCountDispatch: (unit, action) => unit;

  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  let make: {. "children": React.element} => React.element;
};