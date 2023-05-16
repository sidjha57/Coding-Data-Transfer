import mysql from "mysql"

export const db = mysql.createConnection({
    host: "localhost",
    user: "sid",
    password: "MySpace@9146",
    database: "Blog"
});

