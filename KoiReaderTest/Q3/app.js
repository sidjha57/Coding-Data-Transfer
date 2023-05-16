import express from "express"
import got from "got"
import fs from "fs"



const MAX_RETRIES = 3;
const RETRY_INTERVAL = 5000;
const DATA_DIR = 'data';


const makeRequestWithRetry = async (url, retryCount = 0) => {
    try {
        const {body} = await got.get(url);
        const filePath = `./${DATA_DIR}/response.json`
        fs.writeFile(filePath, body, err => {
            if (err) {
                console.log('Error writinf file', err)
            } else {
                console.log('Successfully wrote file')
            }
        });
        return body;
    } catch (err) {
        console.log(err)
        if (retryCount < MAX_RETRIES) {
            console.error(`Request failed. Retrying in ${RETRY_INTERVAL / 1000} seconds...`);
            await new Promise(resolve => setTimeout(resolve, RETRY_INTERVAL));
            return makeRequestWithRetry(url, retryCount + 1)
        } else {
            console.error('Maximum retries exceeded');
            throw err;
        }
    }
}

const app = express();
const port = 8000;
const getFromAPI = 'https://restcountries.com/v3.1/lang/german';

app.get("/api", async (req, res) => {
    try {
        const responseData = await makeRequestWithRetry(getFromAPI);
        res.status(200).json(JSON.parse(responseData))
    } catch (err) {
        res.status(500).json({message: 'Internal Server Error', error : err})
    }
})

app.listen(port, () => {
    console.log(`Server listening on port ${port}`)
})