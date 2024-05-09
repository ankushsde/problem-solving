class Solution
{
public:
    double myPow(double x, int n)
    {
        // Brute force

        // approach: looping from 1 to n, and keeping an ans variable,now everytime the loop runs multiply x with ans.
        // TC: O(n) SC: O(1)
         double ans = 1.0;
         for(int i = 0; i< abs(n) ; i++){
             ans = ans*x;
         }
         return (n>0) ? ans : (1/ans);

        // Better:
        
        // approach: if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.
        // TC: O(log n) SC:O(1)
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};