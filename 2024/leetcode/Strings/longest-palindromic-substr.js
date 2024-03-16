/**
 * @param {string} s
 * @return {number}
 */


const LCS = (a, b) => {
    const n = a.length;
    const m = b.length;

    // base condition
    if (n === 0 || m === 0) {
        return 0;
    }

    // create the table
    const t = new Array(n + 1).fill(-1);
    for (let i = 0; i < n + 1; i++) {
        t[i] = new Array(m + 1).fill(-1)
    }

    // if any string has no length, then value 0
    for (let i = 0; i < n + 1; i++) {
        for (let j = 0; j < m + 1; j++) {
            if (i === 0 || j === 0) {
                t[i][j] = 0;
            }
        }
    }

    // main condition
    for (let i = 1; i < n + 1; i++) {
        for (let j = 1; j < m + 1; j++) {
            if (a[i - 1] === b[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            } else {
                t[i][j] = Math.max(t[i - 1][j], t[i][j - 1])
            }
        }
    }

    return t[n][m];
}
var longestPalindromeSubseq = function(s) {
        return LCS(s, s.split("").reverse().join(""));
    
};