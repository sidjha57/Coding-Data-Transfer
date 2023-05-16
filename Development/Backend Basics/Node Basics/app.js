const http = require('http');
const routes = require('../routes')

const server = http.createServer(routes);

// this file is on going listening
server.listen(8800);
