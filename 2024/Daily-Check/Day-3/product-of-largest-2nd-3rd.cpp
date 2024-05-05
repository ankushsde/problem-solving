#include <bits/stdc++.h> 
vector<long long> multiplication(vector<int> & arr){
	// Write your code here. 
	vector<long long > res; 

    if(arr.size()<=2){
		for(int i = 0; i< arr.size(); i++){
			res.push_back(-1);
		}
		return res;
	}

	long long largest = max(arr[0],arr[1]);
	long long secondLargest = min(arr[0],arr[1]);
	long long thirdLargest = LLONG_MIN;

	res.push_back(-1);
	res.push_back(-1);

    for(int i = 2; i<arr.size(); i++){
		   if(arr[i]> largest){
			   thirdLargest = secondLargest;
			   secondLargest = largest;
			   largest = arr[i];
 		   }
		   else if(arr[i]>secondLargest){
			   thirdLargest = secondLargest;
			   secondLargest = arr[i];
		   } 
		   else if(arr[i]>thirdLargest){
			   thirdLargest = arr[i];
		   }

		   long long product = (thirdLargest != LLONG_MIN)? largest * secondLargest * thirdLargest : -1;
		   res.push_back(product);
	}
 return res;

}
