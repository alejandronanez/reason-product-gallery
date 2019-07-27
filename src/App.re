[@react.component]
let make = () => {
  <div>
    <div className="flex bg-gray-800 text-gray-100">
      <SectionContainer> <Navigation /> </SectionContainer>
    </div>
    <SectionContainer>
      <section className="flex flex-col md:flex-row mt-3">
        <aside className="sm:w-full md:w-1/3 p-4">
          <nav>
            <h2 className="text-xl font-extrabold">
              "All categories"->React.string
            </h2>
            <CategoriesList />
          </nav>
          <nav>
            <h2 className="text-xl font-extrabold mt-3">
              "Filters"->React.string
            </h2>
            <ul>
              <NavigationPill> "Min"->React.string </NavigationPill>
              <NavigationPill> "Max"->React.string </NavigationPill>
            </ul>
          </nav>
        </aside>
        <main className="md:w-2/3 p-4"> <ProductsList /> </main>
      </section>
    </SectionContainer>
  </div>;
};