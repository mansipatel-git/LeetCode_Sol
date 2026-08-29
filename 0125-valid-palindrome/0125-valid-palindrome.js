/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let str = "";
    for(let ch of s){
        if(/[a-zA-Z0-9]/.test(ch)){
            str += ch.toLowerCase();
        }
    }

    let l =0;
    let r = str.length - 1;

    while(l < r){
        if(str[l] !== str[r]){
            return false;
        }
        l++;
        r--;
    }

    return true;
};