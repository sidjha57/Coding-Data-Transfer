const mysql = require('mysql2');

const pool = mysql.createPool({
    host: "localhost",
    user: "sid",
    password: "MySpace@9146",
    database: "Ecommerce"
});

module.exports = pool.promise();