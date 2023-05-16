function x () {
    console.log("x");
}

function y (x) {
    console.log("y");
    x();
}










// What is a Callback Function in JavaScript
// setTimeout(function () {
//     console.log("timer");
// }, 5000);

// function x(y) {
//     console.log("x");
//     y();
// }
// x (function y() {
//     console.log("y");
// })

// JavaScript is a synchtonous and single-threaded
// setTimeout(function () {
//     console.log("timer");
// }, 5000);

// for (let i=1; i<10000000000; i++) ;

// console.log("loop completed");















// // Function Statement aka Function Declaration
// function a() {
//     console.log("a called");
// }

// // Function Expression
// var b = function() {
//     console.log("b called");
// }

// // Anonymous Function

// /*
// function () {

// }
// */

// // Named Function Expression

// var c = function xyz() {
//     console.log("c is called");
// }

// // Difference between Parameters and Arguments?

// function d (param1, param2) {
//     console.log("d is called");
// }

// d(arg1, arg2);

// // First Class Functions
// var e = function (param1) {
//     return function ghi() {

//     }
// }
// e(b);





// function a() {
//     c();
//     function  c() {
//         console.log(b);
//         console.log(this.b);
//     }
// }

// a();
// console.log(b);


