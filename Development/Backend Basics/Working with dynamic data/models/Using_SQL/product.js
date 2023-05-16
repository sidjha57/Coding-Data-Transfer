
const db = require('../../util/sqlDatabase');

module.exports = class Product {
  constructor(id, title, imageUrl, description, price) {
    this.id = id;
    this.title = title;
    this.imageUrl = imageUrl;
    this.description = description;
    this.price = price;
  }

  save() {
    const q = 'INSERT INTO products (`title`, `price`, `imageUrl`, `description`) VALUES (?, ?, ?, ?)';
    return db.execute(q, [this.title, this.price, this.imageUrl, this.description]); 
  }

  static deleteById(id) {
   
  }

  static fetchAll() {
    const q = 'SELECT * FROM products';
    return db.execute(q)
    
  }

  static findById(id) {
    const q = 'SELECT * FROM products WHERE products.id = ?';
    return db.execute(q, [id]);
  }
};
