// In this question, we're supposed to replace the tsring with the giving placeholder, from the dict
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void replaceStr(string &s, unordered_map<string, string> &dict) {
    size_t start_pos = 0;
    while((start_pos = s.find('%', start_pos)) != string::npos) {
        size_t end_pos = s.find('%', start_pos + 1);
        if(end_pos == string::npos) break; // No closing '%'
        
        string key = s.substr(start_pos + 1, end_pos - start_pos - 1);
        
        if(dict.find(key) != dict.end()) {
            s.replace(start_pos, end_pos - start_pos + 1, dict[key]);
        } else {
            start_pos = end_pos + 1;
        }
    }
}

int main() {
    // string s = "home/usr/lib/%EXAMPLE%/cool/%DATE%/check";
    string s = "Hi %EXAMPLE% how are you doing today %DATE%?";
    unordered_map<string, string> dict = {{"EXAMPLE", "testfile.txt"}, { "DATE", "01/01/2024"}};
    
    replaceStr(s, dict);
    
    cout << s << endl;
    
    return 0;
}

// Tc: O(n)
// SC: O(1)