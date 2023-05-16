const person = {
    name: 'Sid',
    age: 21,
    // greet: () => {
    //     // this refers to whoever called a method that uses this
    //     console.log('Hi, I am ' + this.name); // this will return undefined
    // }

    greet()  {
        
        console.log('Hi, I am ' + this.name); // we can use this or directly add function keyword 
    }
}

// person.greet();


// Object Destructing


const printName = ({name}) => {
    console.log(name);
}

printName(person);

const {name, age} = person; // pulls out info which is required
console.log(name, age);


// arrays 
// const hobbies = ['Sports', 'Cooking'];

// for (let hobby of hobbies) {
//     console.log(hobby);
// }

// this creates a new array
// console.log(hobbies.map(hobby => {
//     return 'Hobby: ' + hobby; 
// }));  
// console.log(hobbies);


// hobbies.push('Programming'); // this will add in the array
// console.log(hobbies);

// const copiedArray = hobbies.slice(); // creates a copy
// const copiedArray = [...hobbies]; // spread array pulls out all the values and pushes one by one in the array

// const copiedPerson = {...person}; // works similarly for objects
// console.log(copiedArray);


// // this is called rest operator to merge multiple arguments for an array
// const toArray = (...args) => {
//     return args;
// }

// console.log(toArray(1, 2, 3, 4));

// array destructuring

// const [hobby1, hobby2] = hobbies;
// console.log(hobby1, hobby2);

