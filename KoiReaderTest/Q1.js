// Write a function that takes string as input and returns count of each character in an object.
// Input - “Smart Operations & Edge Computing Platform”
// Output - {'S': 1, 'm': 3, 'a': 3, 'r': 3, 't': 4, ' ': 5, 'O': 1, 'p': 2, 'e': 2, 'i': 2, 'o': 3, 'n': 2, 's': 1, '&': 1, 'E':
// 1, 'd': 1, 'g': 2, 'C': 1, 'u': 1, 'P': 1, 'l': 1, 'f': 1}

function count_occurences (input) {
    const freq = new Map()
    for (let i=0; i<input.length; i++) {
        
        if (freq.has(input[i])) {
            const count = freq.get(input[i]) + 1;
            freq.set(input[i], count);
        } else {
            freq.set(input[i], 1);
        }
    }

    return freq
}

console.log(count_occurences("Smart Operations & Edge Computing Platform"))
