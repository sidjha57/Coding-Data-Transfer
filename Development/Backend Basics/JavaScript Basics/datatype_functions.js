//let and const are lexically scoped var isn't

const name = "Siddharth";
let age = 20;
let hobbies = "chess";


// functions
function describe(myname,myage,myhobbies) {
    return (
      "My name is " +
      myname +
      ". My age is " +
      myage +
      ". My hobbies are: " +
      myhobbies
    );
}


const add = (a,b) => {
  return a + b;
}

// if you have just one argument
const addOne = a => a + 1;

// if no argument
const addRandom = () => 1+2;

console.log(add(1,2));

console.log(describe(name,age,hobbies));

