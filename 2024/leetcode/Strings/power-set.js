// using Power Set

function allPossibleStrings(s) {
    const n = s.length;
    const ans = [];
    for (let num = 0; num < (1 << n); num++) {
        let sub = "";
        for (let i = 0; i < n; i++) {
            if (num & (1 << i)) {
                sub += s[i];
            }
        }
        if (sub.length > 0) {
            ans.push(sub);
        }
    }
    ans.sort();
    return ans;
}

function main() {
    const s = "abc";
    const ans = allPossibleStrings(s);
    console.log("All possible subsequences are:");
    for (const it of ans) {
        console.log(it);
    }
}

main();


// using recurssion
function solve(i, s, f) {
    if (i === s.length) {
        console.log(f + " ");
        return;
    }
    // picking
    f += s[i];
    solve(i + 1, s, f);
    // popping out while backtracking
    f = f.slice(0, -1);
    solve(i + 1, s, f);
}

function main() {
    const s = "abc";
    let f = "";
    console.log("All possible subsequences are:");
    solve(0, s, f);
}

main();


