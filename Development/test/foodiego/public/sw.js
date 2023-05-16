self.addEventListener('install', evt => {
    console.log('service worker install');
})

self.addEventListener('activate', evt => {
    console.log('service worker has been activated');
})

self.addEventListener('fetch', evt => {
    console.log('service worker has been fetched');
})