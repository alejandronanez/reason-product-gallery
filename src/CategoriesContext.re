module type CategoriesContext = {
  type state = {
    categories: option(list(Data.category)),
    selectedCategory: option(Data.category),
  };

  type action =
    | SelectCategory
    | CategoriesFetched(option(list(Data.category)));

  let useCategoriesState: unit => state;
  let useCategoriesDispatch: (unit, action) => unit;

  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  let make: {. "children": React.element} => React.element;
};

module CategoriesContext: CategoriesContext = {
  type state = {
    categories: option(list(Data.category)),
    selectedCategory: option(Data.category),
  };

  type action =
    | SelectCategory
    | CategoriesFetched(option(list(Data.category)));

  let initialState = {categories: None, selectedCategory: None};
  let reducer = (state, action) =>
    switch (action) {
    | SelectCategory => state
    | CategoriesFetched(categories) => {...state, categories}
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

    React.useEffect0(() => {
      External.getCategories()
      |> Js.Promise.then_(value => {
           dispatch(CategoriesFetched(Some(value)));
           Js.Promise.resolve(value);
         })
      |> ignore;
      None;
    });

    <CategoriesStateProvider value=state>
      <CategoriesDispatchProvider value=dispatch>
        children
      </CategoriesDispatchProvider>
    </CategoriesStateProvider>;
  };
};