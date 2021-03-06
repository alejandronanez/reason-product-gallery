[%raw {|require('./styles/ProductList.css')|}];

[@react.component]
let make = (~products) => {
  Data.Product.(
    <ul className="ProductList">
      {products
       ->Belt.List.map(product =>
           <li key={product->idGet->string_of_int}>
             <ProductCard
               name={product->nameGet}
               image={product->imagesGet->mediumGet}
               description={product->descriptionGet}
             />
           </li>
         )
       ->Belt.List.toArray
       ->React.array}
    </ul>
  );
};