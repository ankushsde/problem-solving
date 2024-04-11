// kth largest sum subarray
approach 1 : calculate sum and and, use smStore vector to store the sum, then return 
sumStore[sumStore-k]. TC: n^2logn SC: n^2.

approach 2: using heap , find sum using two pointers using i = 0, j = i, and use sum variable to store the sum inside nested loops.

use min heap, priority_queue<int,vectaor<int>, greater<int>> mini;

if(mini.size() < k ) {
mini.push(sum);
}

else if (sum>mini.top()){
  mini.pop();
  mini.push(sum);
}

return mini.top();
