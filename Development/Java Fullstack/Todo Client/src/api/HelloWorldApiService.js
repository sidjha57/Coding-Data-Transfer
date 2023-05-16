import { apiClient } from "./ApiClient";

export const retriebeHelloWorldPathVariable
    = (username) => apiClient.get(`hello-world/path-variable/${username}`);

    