const { Sequelize } = require('sequelize');

const sequelize = new Sequelize("Node_Course", "sid", "MySpace@9146", {
  dialect: "mysql",
  host: "localhost",
  // password: 'MySpace@9146',
});

module.exports = sequelize;