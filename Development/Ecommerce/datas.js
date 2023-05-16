'use strict';

const fs = require('fs')
const data = require('./data/db1.json');

data.map((product) => {
    product.price = Math.floor((Math.random() * 1000) + 10);
    product.item_count = Math.floor((Math.random() * 10));
    console.log(product)
})

// console.log(data)

fs.writeFile('./products.json', JSON.stringify(data, null, 2), err => {
    if (err) {
        console.log(err);
    } else {
        console.log('File successfully written')
    }
})

