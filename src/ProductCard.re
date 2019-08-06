[@react.component]
let make = (~name, ~description, ~image) => {
  <div className="h-full rounded overflow-hidden shadow-lg">
    <img className="w-full" src=image alt="Sunset in the mountains" />
    <div className="px-6 py-4">
      <div className="font-bold text-xl mb-2"> name->React.string </div>
      <p className="text-gray-700 text-base"> description->React.string </p>
    </div>
  </div>;
};