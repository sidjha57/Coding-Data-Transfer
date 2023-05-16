const obj = {
    a: 1,
    b: 2,
    c: {
        x: 4,
        y: 5
    }
}
 
// obj1 should be copy of obj
let obj1 = {...obj}; // deep cloning // JSON.stringify JSON.parse
obj1.c.x = 7; // 

console.log(obj); // a:1, b: 2, c: {x:7, y:5}
console.log(obj1);

