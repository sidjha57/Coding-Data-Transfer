let deferredPrompt;
window.addEventListener('beforeinstallprompt', (e) => {
    // e.preventDefault();
    deferredPrompt = e;
    console.log(`'beforeinstallprompt' event was fired.`, e);
});

window.addEventListener('appinstalled', () => {
    deferredPrompt = null;
    console.log('PWA was installed');
});

console.log(deferredPrompt)

const installApp = document.getElementById('installApp');

installApp.addEventListener('click', async () => {
    if (deferredPrompt !== null) {
        deferredPrompt.prompt();
        const { outcome } = await deferredPrompt.userChoice;
        if (outcome === 'accepted') {
            deferredPrompt = null;
            location.reload()
        }
    }
});

if (window.matchMedia('(display-mode: standalone)').matches) {
  console.log("Installed")
  document.getElementById('BeforeInstall').style.display = "none";
  document.getElementById('AfterInstall').style.display = "show";
} else {
  console.log("Not Installed")
  document.getElementById('BeforeInstall').style.display = "show";
  document.getElementById('AfterInstall').style.display = "none";
}