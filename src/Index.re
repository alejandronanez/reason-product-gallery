[%raw {|require('./styles/index.css')|}];

// Aliasing CategoriesContext module so we don't have to write
// CategoriesContext.CategoriesContext which is pretty ugly
module CategoriesProvider = CategoriesContext.CategoriesContext;

ReactDOMRe.renderToElementWithId(
  <CategoriesProvider> <App /> </CategoriesProvider>,
  "app",
);