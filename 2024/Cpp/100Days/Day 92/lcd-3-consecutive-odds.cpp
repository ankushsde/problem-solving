class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0; 

        for(int i = 0 ; i< arr.size();i++){
        if(arr[i] %2 != 0){
            count++;

            if(count == 3){
                return true;
            }
         } else {
            count = 0;
         }
        }
        return false;
    }
};

// 
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()==1||arr.size()==2)
        return false;
        for(int i=0;i<arr.size()-2;i++)
        {
            if(arr[i]%2!=0)
            {
                if(arr[i+1]%2 !=0 && arr[i+2]%2 !=0)
                {
                   return true;
                }
            }

        }
      return false;  
    }
};