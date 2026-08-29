/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {

    if (s.length !== t.length) {
        return false;
    }

    let freq = new Array(26).fill(0);

    for (let c of s) {
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let c of t) {
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]--;
    }

    for (let x of freq) {
        if (x !== 0) {
            return false;
        }
    }

    return true;
};