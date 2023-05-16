const path = require('path');

const express = require('express');

const rootDir = require('../util/path');


const router = express.Router();

router.get('/', (req, res, next) => {
    console.log('At home page');

    res.sendFile(path.join(rootDir, 'views', 'shop.html')); // path join detects OS and builds the absoulute path
    //dirname points to the routes folder
})

module.exports = router;