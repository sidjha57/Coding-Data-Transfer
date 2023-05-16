var a = 10
let b = 20
const c = 30

{
    var a = 100
    let b = 30
    console.log(a) // => 100
    console.log(b) //=> 30
}

console.log(a) // => 100
console.log(b) // => 20