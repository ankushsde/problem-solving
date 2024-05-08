#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> breakString(const string& s, int k) {
    vector<string> result;
    int start = 0;
    int end = k;
    
    while (start < s.length()) {
         while (end < s.length() && s[end] != ' ')
            end--;
        
         if (end == start) {
            result.clear();
            return result;
        }
        
         result.push_back(s.substr(start, end - start));
        
         start = end + 1;
        end = start + k;
    }
    
    return result;
}

int main() {
    string s = "the quick brown fox jumps over the lazy dog";
    int k = 10;
    
    vector<string> lines = breakString(s, k);
    
    if (lines.empty()) {
        cout << "null" << endl;
    } else {
        for (const string& line : lines) {
            cout << line << endl;
        }
    }
    
    return 0;
}
