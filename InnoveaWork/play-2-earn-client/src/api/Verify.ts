import { apiClient } from "./ApiClient"

// const userResp: UserType = {
//   id: 1,
//   name: "Mohammad Khalid",
//   phonenum: "9511877596",
// }

// export const verifyUserApi = (phonenum: string): any => 
//   Promise.resolve({ data: { status: 200, data: userResp } })
  
export const verifyUserApi = (phoneNumber: string): any => {
  const query = {
    "where": {
      "phoneNumber": phoneNumber
    },
    "fields": {
      "emailId": true,
      "firstName": true,
      "ipid": true,
      "lastName": true,
      "middleName": true,
      "phoneNumber": true
    }
  }

  return apiClient.get(`/user-datamodel?filter=${JSON.stringify(query)}`)
}

