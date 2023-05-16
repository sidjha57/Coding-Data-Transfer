export const addDataIntoCache = (cacheName, url, response) => {
    const data = new Response (JSON.stringify(response));  
    if ('caches' in window) {
      caches.open(cacheName).then((cache) => {
        cache.put(url, data);
      });
    
    }
  };

 export const getDataFromCache = async (cacheName, url) => {
    return caches.open(cacheName).then (async cache => {
        const res = await cache.match(url);
        const data = await res.json();
        return data;
    })
 }

