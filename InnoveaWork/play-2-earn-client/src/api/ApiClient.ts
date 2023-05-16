import axios from "axios"
import { backendUrl } from "../js/urls"


export const apiClient = axios.create({
  baseURL: backendUrl,
})
