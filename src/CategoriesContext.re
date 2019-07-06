module type CategoriesContext = {
  type categories =
    | Loading
    | Error
    | Loaded(list(Data.category));

  type state = {categories};

  type action =
    | CategoriesFetch
    | CategoriesFailedToFetch
    | CategoriesFetched(list(Data.category));

  let useCategoriesState: unit => state;
  let useCategoriesDispatch: (unit, action) => unit;

  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  let make: {. "children": React.element} => React.element;
};

module CategoriesContext: CategoriesContext = {
  type categories =
    | Loading
    | Error
    | Loaded(list(Data.category));

  type state = {categories};

  type action =
    | CategoriesFetch
    | CategoriesFailedToFetch
    | CategoriesFetched(list(Data.category));

  let initialState = {categories: Loading};
  let reducer = (_, action) =>
    switch (action) {
    | CategoriesFetched(data) => {categories: Loaded(data)}
    | CategoriesFetch => {categories: Loading}
    | CategoriesFailedToFetch => {categories: Error}
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

  let populateCategoriesData = (dispatch, ()) => {
    External.getCategories()
    |> Js.Promise.then_((response: array(Data.category)) => {
         CategoriesFetched(response->Array.to_list)->dispatch;
         Js.Promise.resolve(response);
       })
    |> ignore;
    None;
  };

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) = React.useReducer(reducer, initialState);

    React.useEffect0(populateCategoriesData(dispatch));

    <CategoriesStateProvider value=state>
      <CategoriesDispatchProvider value=dispatch>
        children
      </CategoriesDispatchProvider>
    </CategoriesStateProvider>;
  };
};