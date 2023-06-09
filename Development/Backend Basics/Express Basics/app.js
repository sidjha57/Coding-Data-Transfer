const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');
const rootDir = require('./util/path');


const app = express();


const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');

app.use(bodyParser.urlencoded({extended: true})) // this is a middleware it will do the complete parse
app.use(express.static(path.join(__dirname, 'public')))
// app.use(); // use allows us to use a middleware function

// app.use((req,res,next) => {
//     console.log('In the middleware');
//     next(); // Allows the request to continue to the next middleware
// });


app.use('/admin',adminRoutes);
app.use(shopRoutes);


app.use((req, res, next) => {
    res.status(404).sendFile(path.join(rootDir, 'views', '404.html'));
})


app.listen(8000, () => {
    console.log("Connected!")
})