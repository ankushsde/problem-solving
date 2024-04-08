#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findMatchesCount(const vector<string>& arr, const string& pref) {
    int count = 0;

    // Iterate through each string in arr
    for (int i = 0; i < arr.size(); ++i) {
        // Check if the string starts with pref
        if (arr[i].compare(0, pref.length(), pref) == 0) {
            // If it does, increment the count
            count++;
        }
    }

    return count;
}

int main() {
    vector<string> arr = {"dog", "dark", "door", "dodge", "cat"};
    string pref = "do";

    int matchingCount = findMatchesCount(arr, pref);

    // Print the count of matching words
    cout << "Count of words matching prefix \"" << pref << "\": " << matchingCount << endl;

    return 0;
}
