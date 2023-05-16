import { apiClient } from "./ApiClient";

export const executesBasicAuthenticationService
= (token) => apiClient.get(`/basicauth`, {
    headers: {
        Authorization: token
    }
})

export const executesJwtAuthenticationService
    = (username, password) => apiClient.post(`/authenticate`, {password, username})
          
        
    

