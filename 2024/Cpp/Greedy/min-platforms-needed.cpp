#include<bits/stdc++.h>
 using namespace std;
 
 int findPlatforms(int arr[], int dep[], int n ){
     sort(arr,arr+n);
     sort(dep,dep+n);
     
     int plat_needed = 1, result = 1;
     int i =1, j=0;
     
     while(i<n && j<n){
         if(arr[i]<=dep[j]){
             plat_needed++;
             i++;
         }
         else {
             plat_needed--;
             j++;
         }
         if(plat_needed>result){
             result = plat_needed;
         }
     }
     return result;
 }
  
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<< "Max Platforms : "<< findPlatforms(arr,dep,n)<<endl;
 }