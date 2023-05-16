const http = require('http')

const express = require('express')

const app = express();


// app.use((req,res,next) => {
//     console.log("You have reached the home Page");
//     // res.send('<h1>Home</h1>');
//     next();
// });

// app.use((req,res,next) => {
//     console.log("You have reached the users Page");
//     res.send('<h1>Users</h1>');
// });

app.use('/users', (req,res,next) => {
    console.log("Users Page");
    res.send('<h1>Users Page</h1> <ul>Sid</ul> <ul>Ram</ul> <ul>Shyam</ul>');
});

app.use('/', (req,res,next) => {
    console.log("HOME");
    res.send('<h1>Home Page</h1>');
});

app.listen(8800, ()=> {
    console.log("Connected to assignment")
});