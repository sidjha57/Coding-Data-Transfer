import {createContext, useState, useContext } from "react";
import { apiClient } from "../api/ApiClient";
import { executesJwtAuthenticationService } from "../api/AuthenticationApiService";

// 1: Create a context
export const AuthContext = createContext()

export const useAuth = () => useContext(AuthContext);

// 2: Share the created context with other components

export const AuthProvider = ({children}) => {

    const [username, setUsername] = useState();
    const [isAuthenticated, setAuthenticated] = useState(false);
    const [token, setToken] = useState();

    // Fixed credentials

    // function login (username, password) {
    //     if (username === "sid" && password === "123") {
    //         console.log(username);
    //         setUsername(username);
    //         setAuthenticated(true);
    //         console.log("Success");
    //         return true;
    //       } else {
    //         setAuthenticated(false);
    //         setUsername(null);
    //         console.log("Failed!");
    //         return false;
    //       }
    // }


    // async function login (username, password) {
    //     // e.preventDefault();
    //     const baToken = 'Basic ' + window.btoa(username + ":" + password);

    //     await executesBasicAuthenticationService(baToken)
    //     .then(() => {
    //         console.log(username);
    //         setUsername(username);
    //         setAuthenticated(true);
    //         setToken(baToken);

    //         apiClient.interceptors.request.use(
    //             (config) => {
    //                 console.log('intercepting and adding a token')
    //                 config.headers.Authorization = baToken
    //                 return config
    //             }
    //         )

    //         console.log("Successful");
    //     })
    //     .catch((err) => {
    //         logout()
    //         console.log("Failed!", err);
    //     })
    // }

    async function login (username, password) {
        // console.log(username)
        // console.log(password)

        await executesJwtAuthenticationService(username, password)
        .then((res) => {
            // console.log(res)
            setUsername(username);
            setAuthenticated(true);

            const jwtToken = 'Bearer ' + res.data.token
           
            setToken(jwtToken);

            apiClient.interceptors.request.use(
                (config) => {
                    //console.log('intercepting and adding a token')
                    config.headers.Authorization = jwtToken
                    return config
                }
            )

            // console.log("Successful");
        })
        .catch((err) => {
            logout()
            console.log("Failed!", err);
        })
    }

    function logout() {
        setToken(null)
        setUsername('');
        setAuthenticated(false);
    }


    return (
        <AuthContext.Provider value={ { isAuthenticated, login, logout, username, token} }>
            {children}
        </AuthContext.Provider>
    )
}


