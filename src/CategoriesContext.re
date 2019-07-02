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

module CountStateContextProvider = {
  let make = React.Context.provider(countStateContext);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

module CountDispatchContextProvider = {
  let make = React.Context.provider(countDispatchContext);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

let useCountState = () => React.useContext(countStateContext);
let useCountDispatch = () => React.useContext(countDispatchContext);

[@react.component]
let make = (~children) => {
  let (state, dispatch) = React.useReducer(countReducer, initialState);
  <CountStateContextProvider value=state>
    <CountDispatchContextProvider value=dispatch>
      children
    </CountDispatchContextProvider>
  </CountStateContextProvider>;
};