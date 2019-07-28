module type ProductsContext = {
  type products =
    | Loading
    | Error
    | Loaded(list(Data.Product.product));

  type state = {products};

  type action =
    | ProductsFailedToFetch
    | ProductsFetch
    | ProductsFetched(list(Data.Product.product));

  let useProductsState: unit => state;
  let useProductsDispatch: (unit, action) => unit;
  let updateProductsForCategory:
    (
      ~minPrice: float=?,
      ~maxPrice: float=?,
      ~searchText: string=?,
      ~dispatch: action => 'a,
      ~categoryId: int,
      unit
    ) =>
    option('b);

  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  let make: {. "children": React.element} => React.element;
};

module ProductsContext: ProductsContext = {
  type products =
    | Loading
    | Error
    | Loaded(list(Data.Product.product));

  type state = {products};

  type action =
    | ProductsFailedToFetch
    | ProductsFetch
    | ProductsFetched(list(Data.Product.product));

  let initialState = {products: Loading};
  let reducer = (state, action) =>
    switch (action) {
    | ProductsFetched(_) => state
    | ProductsFetch => state
    | ProductsFailedToFetch => state
    };

  let productsStateContext = React.createContext(initialState);
  let productsDispatchContext = React.createContext(_ => ());
  let useProductsState = () => React.useContext(productsStateContext);
  let useProductsDispatch = () => React.useContext(productsDispatchContext);

  module ProductsStateProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(productsStateContext);
  };

  module ProductsDispatchProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(productsDispatchContext);
  };

  let updateProductsForCategory =
      (
        ~minPrice=0.0,
        ~maxPrice=0.0,
        ~searchText="",
        ~dispatch,
        ~categoryId,
        (),
      ) => {
    External.getProducts(~categoryId, ~minPrice, ~maxPrice, ~searchText)
    |> Js.Promise.then_((response: array(Data.Product.product)) => {
         ProductsFetch->dispatch;
         Js.Promise.resolve(response);
       })
    |> Js.Promise.catch(_ => {
         dispatch(ProductsFailedToFetch);
         Js.Promise.resolve([||]);
       })
    |> ignore;
    None;
  };

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) = React.useReducer(reducer, initialState);

    // React.useEffect0(updateProductsForCategory(~dispatch, ~categoryId=1));

    <ProductsStateProvider value=state>
      <ProductsDispatchProvider value=dispatch>
        children
      </ProductsDispatchProvider>
    </ProductsStateProvider>;
  };
};