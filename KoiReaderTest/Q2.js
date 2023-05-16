// Write a function that takes a city name as input and returns state name as output from the
// following data structure -
// obj = {
// "India" : {
// "Karnataka" : ["Bangalore", "Mysore"],
// "Maharashtra" : ["Mumbai", "Pune"]

// },
// "USA" : {
// "Texas" : ["Dallas", "Houston"],
// "IL" : ["Chicago", "Aurora", "Pune"]

// }
// }
// Input - “Pune”
// Output - [“IL”, “Maharashtra”]

const obj = {
  India: {
    Karnataka: ["Bangalore", "Mysore"],
    Maharashtra: ["Mumbai", "Pune"],
  },

  USA: {
    Texas: ["Dallas", "Houston"],
    IL: ["Chicago", "Aurora", "Pune"],
  },
};

const city_to_state = {};

function map_cities_to_state() {
  const countries = Object.keys(obj);
  countries.forEach((country) => {
    const states = Object.keys(obj[country]);

    states.forEach((state) => {
      // console.log(state);
      const cities = obj[country][state];

      // console.log(typeof(cities));
      cities.map((city) => {
        if (!Object.hasOwn(city_to_state, city)) {
          city_to_state[city] = [];
        }

        city_to_state[city].push(state);
      });
    });
  });
}

function get_state_names(input) {
  return city_to_state[input];
}

map_cities_to_state();

console.log(get_state_names("Houston"));
