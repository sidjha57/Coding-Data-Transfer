const users = [
    {firstName: "sid", lastName: "jha", age: 22},
    {firstName: "abha", lastName: "di", age: 28},
    {firstName: "sejal", lastName: "ullo", age: 21},
    {firstName: "ram", lastName: "bhagwan", age: 22},
];

// list of full names
console.log(users.map(x => x.firstName + " " + x.lastName));


// find the frequency of people with same age
// {22 : 2, 21: 1, 28: 1}
console.log(users.reduce( (acc,cur) => {
    acc[cur.age] ? acc[cur.age]++ : acc[cur.age] = 1;
    return acc;
} , {}));


// firstname of all the people whose age is less than 22
console.log(users.filter((x) => x.age <= 22).map((x) => x.firstName));

console.log(users.reduce((acc, cur) => {
    if (cur.age <= 22) acc.push(cur.firstName);
    return acc;
},[]))









// // filter odd values
// console.log(arr.filter(x => x&1));

// //filter even values
// console.log(arr.filter(x => !(x&1)));

// //filter values greater than 3
// console.log(arr.filter(x => x > 3));










//binary - ["101","1", "11", "10", "110"]
// const binary = function (x) {
//     return x.toString(2);
// }
// console.log(arr.map(binary));
// // OR 
// console.log(arr.map(
//     function (x) {
//         return x.toString(2);
//     }
// ));
// // OR 
// console.log(arr.map((x) => {
//     return x.toString(2);
// }))
















// const circumference = function (radius) {
//     return 2 * Math.PI * radius;
// }

// const diameter = function (radius) {
//     return 2 * radius;
// }

// const radius = [3, 2, 4, 5];

// const area = function (radius) {
//     return Math.PI * radius * radius;
// }

// Array.prototype.calculate = function (logic) {
//     const output = [];
//     for (let i=0; i < this.length; i++) {
//         output.push(logic(this[i]));
//     }
//     return output;
// }

// console.log(radius.calculate(area));
// console.log(radius.map(area));
// console.log(calculate(radius, circumference));
// console.log(calculate(radius, diameter));












// var x = 1;
// a();
// b();
// console.log(x);

// function a() {
//     var x = 10;
//     console.log(x);
// }

// function b() {
//     var x = 100;
//     console.log(x);
// }