module type CategoriesContext = {
  type action =
    | SelectCategory;

  type category = {
    id: string,
    category: string,
  };
  type state = {
    categories: list(category),
    selectedCategory: option(category),
  };

  let useCategoriesState: unit => state;
  let useCategoriesDispatch: (unit, action) => unit;

  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  let make: {. "children": React.element} => React.element;
};

module CategoriesContext: CategoriesContext = {
  type action =
    | SelectCategory;

  type category = {
    id: string,
    category: string,
  };
  type state = {
    categories: list(category),
    selectedCategory: option(category),
  };

  let initialState = {
    categories: [
      {id: "123", category: "Food"},
      {id: "456", category: "Drinks"},
      {id: "789", category: "Toys"},
    ],
    selectedCategory: None,
  };
  let reducer = (state, action) =>
    switch (action) {
    | SelectCategory => state
    };

  let categoriesStateContext = React.createContext(initialState);
  let categoriesDispatchContext = React.createContext(_ => ());
  let useCategoriesState = () => React.useContext(categoriesStateContext);
  let useCategoriesDispatch = () =>
    React.useContext(categoriesDispatchContext);

  module CategoriesStateProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(categoriesStateContext);
  };

  module CategoriesDispatchProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(categoriesDispatchContext);
  };

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) = React.useReducer(reducer, initialState);
    <CategoriesStateProvider value=state>
      <CategoriesDispatchProvider value=dispatch>
        children
      </CategoriesDispatchProvider>
    </CategoriesStateProvider>;
  };
};