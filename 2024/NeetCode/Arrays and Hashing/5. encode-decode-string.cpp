class Solution {
public:

    unordered_map<string, int> strToId;
    unordered_map<int, string> idToStr;
    int idCounter = 1; 

    string encode(vector<string>& strs) {
    
        ostringstream oss;
        for (const string& str : strs) {
            if (strToId.find(str) == strToId.end()) {
                strToId[str] = idCounter;
                idToStr[idCounter] = str;
                idCounter++;
            }
            oss << strToId[str] << " ";
        }
        return oss.str();

    }

    vector<string> decode(string s) {
       istringstream iss(s);
        vector<string> res;
        int id;
        while (iss >> id) {
            res.push_back(idToStr[id]);
        }
        return res;
    }
};


// neetcode way
class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        
        return result;
    }
};


