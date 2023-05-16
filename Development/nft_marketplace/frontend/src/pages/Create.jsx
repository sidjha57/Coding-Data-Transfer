import { useEffect, useState } from "react"
import { getDataFromCache } from "../caching/caches";
import {ethers} from "ethers"
import { Buffer } from 'buffer';
import * as ipfsClient from 'ipfs-http-client'

const projectId = '2MDbWF4Z8tgGootvw1QIcoqJ2AZ';
const projectSecret = 'eb886de9028b36da1eb85654c3fefa8b';
const auth =
    'Basic ' + Buffer.from(projectId + ':' + projectSecret).toString('base64');

const client = ipfsClient.create({
    host: 'ipfs.infura.io',
    port: 5001,
    protocol: 'https',
    headers: {
        authorization: auth,
    },
});

client.pin.add('QmeGAVddnBSnKc1DLE7DLV9uuTqo5F7QbaveTjr45JUdQn').then((res) => {
    console.log(res);
});

const marketplace = getDataFromCache("Marketplace", "http://localhost:5174")
const nft = getDataFromCache("nft", "http://localhost:5174")

export default function Create() {


    const [values, setValues] = useState({
        image: "",
        price: "",
        collection: "",
        name: "",
        description: ""
    });
   
    const uploadToIPFS = async (event) => {
        event.preventDefault()
        const file = event.target.files[0]
        if (typeof file !== 'undefined') {
          try {
            const result = await client.add(file)
            console.log(result)
            setImage(`https://ipfs.infura.io/ipfs/${result.path}`)
          } catch (error){
            console.log("ipfs image upload error: ", error)
          }
        }
      }
      const createNFT = async (e) => {
        e.preventDefault()
        try{
          const result = await client.add(JSON.stringify(values))
          console.log(result);
        //   mintThenList(result)
        } catch(error) {
          console.log("ipfs uri upload error: ", error)
        }
      }
      const mintThenList = async (result) => {
        const uri = `https://ipfs.infura.io/ipfs/${result.path}`
        // mint nft 
        await(await nft.mint(uri)).wait()
        // get tokenId of new nft 
        const id = await nft.tokenCount()
        // approve marketplace to spend nft
        await(await nft.setApprovalForAll(marketplace.address, true)).wait()
        // add nft to marketplace
        const listingPrice = ethers.utils.parseEther(price.toString())
        await(await marketplace.makeItem(nft.address, id, listingPrice)).wait()
      }

      const handleChange = e => {
        setValues(prev =>({...prev, [e.target.name]: e.target.value})) // this updates only the object value which is changed
      };

      console.log(values);

    return (
    
        <div className="m-24">
          <div className="md:grid md:grid-cols-3 md:gap-6">
            <div className="md:col-span-1">
              <div className="px-4 sm:px-0">
                <h3 className="text-2xl font-semibold leading-6 text-gray-900">NFT</h3>
                <p className="mt-1 text-sm text-gray-700">
                  This NFT will be displayed publically once saved it cannot be changed. You will only be able to change the price
                </p>
              </div>
            </div>
            <div className="mt-5 md:col-span-2 md:mt-0">
              <form action="#" method="POST">
                <div className="shadow sm:overflow-hidden sm:rounded-md">
                  <div className="space-y-6 bg-white px-4 py-5 sm:p-6">
                    <div className="col-span-6 sm:col-span-3 ">
                        <label htmlFor="name" className="block text-sm font-medium text-gray-700 ">
                          NFT Name
                        </label>
                        <input
                          onChange={handleChange}
                          type="text"
                          name="name"
                          id="name"
                          autoComplete="given-name"
                          className="mt-1 border-1 border h-10  block w-full rounded-md border-gray-300 shadow-sm hover:border-indigo-500 hover:ring-indigo-500 sm:text-sm"
                        />
                    </div>
                    <div className="col-span-6 sm:col-span-3">
                      <label htmlFor="price" className="block text-sm font-medium text-gray-700" step=".001">
                        Price in ETH
                      </label>
                      <input
                       onChange={handleChange}

                        type="number"
                        name="price"
                        id="price"
                        className="mt-1 border-1 border h-10 block w-full rounded-md border-gray-300 shadow-sm  hover:border-indigo-500 hover:ring-indigo-500 sm:text-sm"
                      />
                    </div>
                    <div className="col-span-6 sm:col-span-3">
                        <label htmlFor="collection" className="block text-sm font-medium text-gray-700">
                          Collection
                        </label>
                        <select
                          id="collection"
                          name="collection"
                          onChange={handleChange}
                          
                          autoComplete="collection-name"
                          className="mt-1 block w-full rounded-md border border-gray-300 bg-white py-2 px-3 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm"
                        >
                          <option value="Art" >Art</option>
                          <option value="Gaming">Gaming</option>
                          <option value="GIF">GIF</option>
                          <option value="Photograph">Photograph</option>
                          <option value="PFPs">PFPs</option>
                        </select>
                      </div>
                    <div>
                      <label htmlFor="description" className="block text-sm font-medium text-gray-700">
                        About
                      </label>
                      <div className="mt-1">
                        <textarea
                          id="description"
                          name="description"
                          onChange={handleChange}
                          rows={5}
                          className="mt-1  text-start border border-1 block w-full rounded-md border-gray-300 shadow-sm hover:border-indigo-500 hover:ring-indigo-500 sm:text-sm"
                          placeholder="   This is a nft made by ..."
                          defaultValue={''}
                        />
                      </div>
                      <p className="mt-2 text-sm text-gray-500">
                        Brief description for your profile. URLs are hyperlinked.
                      </p>
                    </div>
  
              
  
                    <div>
                      <label className="block text-sm font-medium text-gray-700">Add NFT</label>
                      <div className="mt-1 flex justify-center rounded-md border-2 border-dashed border-gray-300 px-6 pt-5 pb-6">
                        <div className="space-y-1 text-center">
                          <svg
                            className="mx-auto h-12 w-12 text-gray-400"
                            stroke="currentColor"
                            fill="none"
                            viewBox="0 0 48 48"
                            aria-hidden="true"
                          >
                            <path
                              d="M28 8H12a4 4 0 00-4 4v20m32-12v8m0 0v8a4 4 0 01-4 4H12a4 4 0 01-4-4v-4m32-4l-3.172-3.172a4 4 0 00-5.656 0L28 28M8 32l9.172-9.172a4 4 0 015.656 0L28 28m0 0l4 4m4-24h8m-4-4v8m-12 4h.02"
                              strokeWidth={2}
                              strokeLinecap="round"
                              strokeLinejoin="round"
                            />
                          </svg>
                          <div className="flex text-sm text-gray-600">
                            <label
                              htmlFor="image"
                              className="relative cursor-pointer rounded-md bg-white font-medium text-indigo-600 focus-within:outline-none focus-within:ring-2 focus-within:ring-indigo-500 focus-within:ring-offset-2 hover:text-indigo-500"
                            >
                              <span>Upload a file</span>
                              <input id="image" name="image" type="file" className="sr-only" onChange={handleChange}/>
                            </label>
                            <p className="pl-1">or drag and drop</p>
                          </div>
                          <p className="text-xs text-gray-500">PNG, JPG, GIF up to 10MB</p>
                        </div>
                      </div>
                    </div>
                  </div>
                  <div className="bg-gray-50 px-4 py-3 text-right sm:px-6">
                    <button
                      type="submit"
                      onClick={createNFT}
                      className="inline-flex justify-center rounded-md border border-transparent bg-indigo-600 py-2 px-4 text-sm font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                    >
                      Save
                    </button>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
  
        
    )
  }
  
    
  
  