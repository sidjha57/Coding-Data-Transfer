// 1 to 100  // no sorting allowed //no inbuilt methods allowed //O(n) Only 1 number is missing. Find that number
// Let array = [1, 2,4 ,5 ,6, …. 100]

// Method 1

// Lets just sum all the numbers in the array is sum 1
// Sum of first natural numbers n(n+1)/2 is sum 2
// missing number = sum 2 - sum 1


function find_missing_number (input) {
    
    const sum2 = (input.length + 1) * (input.length + 2) / 2
    let sum1 = 0

    for (let i=0; i<input.length; i++) {
        sum1 += input[i]
    }

    // console.log(sum1)
    // console.log(sum2) 

    return (sum2 - sum1)
}

console.log(find_missing_number([1,5,2,3]))

// Method 2

// 0001
// 0010
// 0011
// 0100 => 4
// 0101

// 0100 

