const Sequelize = require('sequelize');
const sequilize = require('../../util/sequelizeDatabase');

const Product = sequilize.define('product', {
    id: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNull: false,
        primaryKey: true
    },
    title:  {
        type: Sequelize.STRING,
        allowNull: false,
    },
    price: {
        type: Sequelize.DOUBLE,
        allowNull: false
    },
    description: {
        type: Sequelize.STRING,
        allowNull: false
    },
    imageUrl : Sequelize.STRING
})

module.exports = Product;