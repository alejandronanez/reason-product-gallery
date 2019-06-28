[@react.component]
let make = () =>
  <nav className="py-4 flex flex-wrap justify-between">
    <div className="md:w-1/3">
      <h1 className="font-bold text-2xl">
        "The awesome store"->React.string
      </h1>
    </div>
    <div className="mt-2 w-full md:w-2/3 md:mt-0">
      <form className="relative min-w-full w-full">
        <input
          className="text-gray-900 py-2 px-5 w-full min-w-full"
          type_="search"
          placeholder="Search products by name"
        />
      </form>
    </div>
  </nav>;