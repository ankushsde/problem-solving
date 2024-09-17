class Solution {
public:
    static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()<nums2.size()) return intersect(nums2, nums1);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sz=0, n1=nums1.size(), n2=nums2.size();
        for (int i = 0, j = 0; i < n1 && j < n2;) {
            int x=nums1[i], y=nums2[j];
            if (x==y){
                nums2[sz++] = x;
                i++;
                j++;
            } 
            else if (x<y)// move i such that nums1[i]>=y
                i=lower_bound(nums1.begin()+i+1, nums1.end(), y)-nums1.begin();
            else  // x>y. Move j such that nums2[j]>=x
                j=lower_bound(nums2.begin()+j+1, nums2.end(), x)-nums2.begin();
            
        }
        nums2.resize(sz);
        return nums2; 
    }
};`