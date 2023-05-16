const express = require('express');
const bodyParser = require('body-parser')
const path = require('path');
const rootDir = require('./util/path')

const app = express();

const homeRoutes = require('./routes/home');
const userRoutes = require('./routes/user')

app.use(bodyParser.urlencoded({extended: true}))
app.use(express.static(path.join(__dirname, 'public')))


app.use('/user', userRoutes);
app.use(homeRoutes);

app.use((req, res, next) => {
    res.status(404).sendFile(path.join(rootDir, 'views', '404.html'));
})

app.listen(8000, () => {
    console.log("connected!")
})