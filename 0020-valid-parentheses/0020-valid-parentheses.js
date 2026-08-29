/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {

    let stack = [];

    for (let c of s) {

        // Opening bracket
        if (c === '(' || c === '{' || c === '[') {
            stack.push(c);
        }

        // Closing bracket
        else {

            if (stack.length === 0) {
                return false;
            }

            let top = stack[stack.length - 1];

            if (c === ')' && top !== '(') {
                return false;
            }

            if (c === '}' && top !== '{') {
                return false;
            }

            if (c === ']' && top !== '[') {
                return false;
            }

            stack.pop();
        }
    }

    return stack.length === 0;
};