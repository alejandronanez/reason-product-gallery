module CategoriesContext = {
  type action =
    | Increment
    | Decrement;

  type state = {count: int};

  let initialState = {count: 0};
  let countReducer = (state, action) =>
    switch (action) {
    | Increment => {count: state.count + 1}
    | Decrement => {count: state.count - 1}
    };

  let countStateContext = React.createContext(initialState);
  let countDispatchContext = React.createContext(_ => ());

  module CountStateProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(countStateContext);
  };

  module CountDispatchProvider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(countDispatchContext);
  };

  let useCountState = () => React.useContext(countStateContext);
  let useCountDispatch = () => React.useContext(countDispatchContext);

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) = React.useReducer(countReducer, initialState);
    <CountStateProvider value=state>
      <CountDispatchProvider value=dispatch> children </CountDispatchProvider>
    </CountStateProvider>;
  };
};