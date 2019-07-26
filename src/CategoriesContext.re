module type CategoriesContext = {
  type categories =
    | Loading
    | Error
    | Loaded(list(Data.category));

  type selectedCategory = option(Data.category);

  type state = {
    categories,
    selectedCategory,
  };

  type action =
    | CategoriesFailedToFetch
    | CategoriesFetch
    | CategoriesFetched(list(Data.category))
    | SelectCategory(Data.category);

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

  type selectedCategory = option(Data.category);

  type state = {
    categories,
    selectedCategory,
  };

  type action =
    | CategoriesFailedToFetch
    | CategoriesFetch
    | CategoriesFetched(list(Data.category))
    | SelectCategory(Data.category);

  let initialState = {categories: Loading, selectedCategory: None};
  let reducer = (state, action) =>
    switch (action) {
    | CategoriesFetched(data) => {...state, categories: Loaded(data)}
    | CategoriesFetch => {...state, categories: Loading}
    | CategoriesFailedToFetch => {...state, categories: Error}
    | SelectCategory(selectedCategory) => {
        ...state,
        selectedCategory: Some(selectedCategory),
      }
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
         SelectCategory(response->Array.get(0))->dispatch;
         Js.Promise.resolve(response);
       })
    |> Js.Promise.catch(_ => {
         dispatch(CategoriesFailedToFetch);
         Js.Promise.resolve([||]);
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