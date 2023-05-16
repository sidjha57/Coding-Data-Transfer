const fs = require('fs');

const requestHandler = (req,res) => {
    const url = req.url;
    const method = req.method;
    if (url === '/') {
        res.write('<html>');
        res.write('<head><title> My First Page </title><head>');
        res.write('<body><form action="/message" method="POST"><input type="text" name="message"> <button type="submit">Send</button></form></body>');
        res.write('</html>');
        return res.end(); // return from the message we need to quit because we cannot run anything after res.end()
    }
    // console.log(req.url, req.method, req.headers);
    // process.exit();
    if (url === '/message' && method === 'POST') {
        const body = []; //empty array
        req.on('data', (chunk) => {
            console.log(chunk);
            body.push(chunk);
        });
        return req.on('end', () => {
            const parsedBody = Buffer.concat(body).toString();
            const message = parsedBody.split('=')[1];
            // writeFileSync will block the thread
            fs.writeFile('message.txt', message, (err) => {
                // console.log(err);
                res.statusCode = 302;
                res.setHeader('Location', '/');
                return res.end();
            }); 
        })
    }
    res.setHeader('Content-Type', 'text/html');
    res.write('<html>');
    res.write('<head><title> My First Page </title><head>');
    res.write('<body><h1>This is my first Node Request</h1></body>');
    res.write('</html>');
    res.end();
};

module.exports = requestHandler;

// module.exports = {
//     handler: requestHandler,
//     sometext: 'Some hard coded text'
// };