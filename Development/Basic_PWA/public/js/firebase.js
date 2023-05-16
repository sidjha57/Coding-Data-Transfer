  // Import the functions you need from the SDKs you need
  import {getFirestore, collection, getDocs} from "https://www.gstatic.com/firebasejs/9.15.0/firebase-firestore.js";
  import { initializeApp } from "https://www.gstatic.com/firebasejs/9.15.0/firebase-app.js";
  import { getAnalytics } from "https://www.gstatic.com/firebasejs/9.15.0/firebase-analytics.js";
  // TODO: Add SDKs for Firebase products that you want to use
  // https://firebase.google.com/docs/web/setup#available-libraries

  // Your web app's Firebase configuration
  // For Firebase JS SDK v7.20.0 and later, measurementId is optional
  const firebaseConfig = {
    apiKey: "AIzaSyAWCoEg17M74UChW_e5lgvgy0HKab6nyfI",
    authDomain: "foodiego-82820.firebaseapp.com",
    projectId: "foodiego-82820",
    storageBucket: "foodiego-82820.appspot.com",
    messagingSenderId: "384956372719",
    appId: "1:384956372719:web:39648a5f7a7417288fad1a",
    measurementId: "G-84YWE33EZ5"
  };

  // Initialize Firebase
  const app = initializeApp(firebaseConfig);
  const analytics = getAnalytics(app);
  const db = getFirestore(app);

  const value = async () => {

    const recipesCol = collection(db, 'recipes');
    const recipeSnapshot = await getDocs(recipesCol);
    const recipeList = recipeSnapshot.docs.map(doc => doc.data());
    return recipeList;
  }
  value().then(res => console.log(res));


  