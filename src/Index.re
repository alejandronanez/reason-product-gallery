[%raw {|require('./styles/index.css')|}];

ReactDOMRe.renderToElementWithId(
  <CategoriesContext.CategoriesContext>
    <App />
  </CategoriesContext.CategoriesContext>,
  "app",
);