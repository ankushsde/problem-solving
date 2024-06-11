// Brute force :
// Can be done using sorting, sort both the strings and compare each character
// TC: O(nlogn) SC: O(1);

// *rem : : : edge case, if the length of the strings are not equal return false;
class Solution {
public:
    bool isAnagram(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
 
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i =0; i<str1.size(); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;

    }
};


// Better: using a frequency array; TC: O(n), SC: o(1)
class Solution { 
public:
    bool isAnagram(string str1, string str2) {
      if (str1.length() != str2.length())
            return false;

        int freq[52] = {0}; // 26 for 'A'-'Z' and 26 for 'a'-'z'

        for (int i = 0; i < str1.length(); i++) {
            if (isupper(str1[i])) {
                freq[str1[i] - 'A']++;
            } else if (islower(str1[i])) {
                freq[str1[i] - 'a' + 26]++;
            }
        }

        for (int i = 0; i < str2.length(); i++) {
            if (isupper(str2[i])) {
                freq[str2[i] - 'A']--;
            } else if (islower(str2[i])) {
                freq[str2[i] - 'a' + 26]--;
            }
        }

        for (int i = 0; i < 52; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;   
    }
};

bool CheckAnagrams(string str1, string str2)
{
  // when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;
 
  int freq[26] = {0};
  for (int i = 0; i < str1.length(); i++)
  {
    freq[str1[i] - 'A']++;
  }
  for (int i = 0; i < str2.length(); i++)
  {
    freq[str2[i] - 'A']--;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
      return false;
  }
  return true;
}
