const path = require('path');

const express = require('express');

const rootDir = require('../util/path');


const router = express.Router();

router.get('/', (req, res, next) => {
    console.log('At home page');

    res.sendFile(path.join(rootDir, 'views', 'home.html')); // path join detects OS and builds the absoulute path
})

module.exports = router;