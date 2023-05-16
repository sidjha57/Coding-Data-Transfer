const http = require('http');

const server = http.createServer((req,res) => {
    const url = req.url;
    const method = req.method;
    if (url === '/') {
        res.setHeader('Content-Type', 'text/html');
        res.write('<html>');
        res.write('<head><title>Users Page</title></head>');
        res.write('<body><h1>Welcome Everyone</h1> <form action="/create-user" method="POST"><input type="text" name="username"><button type="submit">Send</button></form></body>');
        res.write('</html>');
        return res.end();
    }
    if (url === '/users') {
        res.setHeader('Content-Type', 'text/html');
        res.write('<html>');
        res.write('<head><title>Users Page</title></head>');
        res.write('<body><ul><li>Siddharth</li> <li>Abha</li> <li>Sejal</li></ul></body>');
        res.write('</html>');
        return res.end();
    }
    if (url === '/create-user' && method === 'POST') {
        const body = [];
        req.on('data', (chunk) => {
            console.log(chunk);
            body.push(chunk);
        });
        req.on('end', () => {
            const parsedBody = Buffer.concat(body).toString();
            const name = parsedBody.split('=')[1];
            console.log(name);
        });
        res.statusCode = 302;
        res.setHeader('Location', '/users');
        return res.end();
    }
});

server.listen(8800);