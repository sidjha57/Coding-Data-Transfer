import { frontendUrl } from "./urls";

export const addDataIntoCache = (cacheName : string, url : string, response : any) => {
    const data = new Response (JSON.stringify(response));  
    if ('caches' in window) {
      caches.open(cacheName).then((cache) => {
        cache.put(url, data);
      });
    
    }
  };

export const getData = async (cacheName : string) =>{
  try{
      const url = frontendUrl;

      let cachedData = await getDataFromCache(cacheName, url);
      
      if (cachedData) {
        console.log("Retrieved cached data");
        return cachedData;
      }
      
      console.log("Fetching fresh data");
      
      const cacheStorage = await caches.open(cacheName);
      await cacheStorage.add(url);
      cachedData = await getDataFromCache(cacheName, url);
      await deleteOldCaches(cacheName);
      
      return cachedData;
    } catch(err) {
      console.log(err)
    }
  
}

 export const getDataFromCache = async (cacheName : string, url : string) => {
 try{

   
   const cacheStorage = await caches.open(cacheName);
   const cachedResponse = await cacheStorage.match(url);
   
  if (!cachedResponse || !cachedResponse.ok) {
    return false;
  }
    
    return await cachedResponse.json();
  } catch(err) {
    console.log(err)
  }
  
 }


// Delete any old caches to respect user's disk space.
async function deleteOldCaches(currentCache : string) {
  const keys = await caches.keys();

  for (const key of keys) {
    const isOurCache = key.startsWith("myapp-");
    if (currentCache === key || !isOurCache) {
      continue;
    }
    caches.delete(key);
  }
}
