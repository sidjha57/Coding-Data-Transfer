const fetchData = callback => {
    const promise = new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve('1500  Timer is done!');
        }, 1500);
    });
    return promise;
};

setTimeout(() => {
    console.log('2000 Timer is done!');
    fetchData()
      .then((text) => {
        // this adding of promise helps in multiple nested async functions
        console.log(text);
        return fetchData();
      })
      .then((text2) => {
        console.log(text2);
      });
}, 2000);

console.log("Hello!");
console.log("Hi!");

// setTimeout(() => {
//     console.log('Timer is done!');
// }, 2000);