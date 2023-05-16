// input: [1,2,[3,4,[5,6], 7], 8, 9,[10,[11]]]
// output: [1,2,3,4,5,6,7,8,9,10,11]

// Method 1

// Iterate over the input and add values to a new array
// Where typeof(input[2]) => array | number 
// function which will iterate over array add the element to the new array

const output = new Array()
const input = [1,2,[3,4,[5,6], 7], 8, 9,[10,[11]]]



function append (input) {
    for (let i=0; i<input.length; i++ ) {
        // console.log(typeof(input[i]))
        if (typeof(input[i]) === "object") {
            // console.log("It is an object")
            append(input[i])
        } else {
            output.push(input[i]);
        }
    }
}

append(input)
console.log(output)



// Method 2 Stacks

// First In Last Out 

// class Stack {
//     constructor (
//         let st = [],
//     )
// }



