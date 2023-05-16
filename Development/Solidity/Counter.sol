//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 
// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.4.16 <0.9.0;
// it is statically typed as in we have ti declare the variable type
contract Counter {
    //uint count = 0; // this is a state variable
    
    uint public count = 1; // after doing this we do not require a getcount function solidity automatically creates a function
    
    // constructor() public {
    //     count  = 0;
    // }
    
    // function getCount() public view returns (uint) {
    //     return count;
    // }
    
    /* whenever we do increment count we create a 
       transaction log its like we are writing data to the
       blockchain it is comprised of bundles of data called 
       transaction grouping of these are in blocks and it is linked
       we are paying for gas
     */
    function incrementCount() public {
        count ++; // we are updating the state variable
    }
}