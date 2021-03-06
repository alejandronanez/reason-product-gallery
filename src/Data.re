module Category = {
  [@bs.deriving abstract]
  type category = {
    id: int,
    name: string,
  };
};

module Product = {
  [@bs.deriving abstract]
  type image = {
    medium: string,
    large: string,
  };

  [@bs.deriving abstract]
  type product = {
    id: int,
    name: string,
    description: string,
    price: float,
    images: image,
    categoryId: int,
  };

  [@bs.deriving {jsConverter: newType}]
  type productInput = {
    categoryId: int,
    minPrice: option(float),
    maxPrice: option(float),
    searchText: option(string),
  };

  type productInputObj = abs_productInput;
};