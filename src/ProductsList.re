[@react.component]
let make = (~products: list(Data.Product.product)) => {
  <ul>
    {products
     ->Belt.List.map(product =>
         <li key={Data.Product.idGet(product)->string_of_int}>
           <ProductCard
             name={Data.Product.nameGet(product)}
             image={Data.Product.mediumGet(Data.Product.imagesGet(product))}
             description={Data.Product.descriptionGet(product)}
           />
         </li>
       )
     ->Belt.List.toArray
     ->React.array}
  </ul>;
};