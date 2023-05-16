const path = require('path');

const express = require('express');
const rootDir = require('../util/path');

const router = express.Router();


router.get('/add-user', (req, res, next) => {
    console.log('At user Page');
    res.sendFile(path.join(rootDir, 'views', 'add-user.html'));
});

router.post('/add-user', (req, res, next) => {
    console.log(req.body);
    res.redirect('/');
})


module.exports = router;