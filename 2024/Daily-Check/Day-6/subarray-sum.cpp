#include <bits/stdc++.h>
using namespace std;

// brute 

int SubarraySum1(int arr[], int N, int sum){
    int currentsum, k, l;
  
    for ( k= 0;  k< N; k++){
         currentsum = arr[k];
       
        for ( l= k+1; l < N + 1; l++){
             if (currentsum == sum){
                cout<<"Subarray with given sum is between indexes "<< k<<" and "<<l-1<<endl; 
                return 1;
            }
            else if (currentsum > sum){
                break;
            }
           currentsum = currentsum + arr[l];
        }
    }
    
    cout<<"Subarray with given sum is NOT Found"<<endl;
    return 0;
}

//Better

int subarray(int arr[] , int n , int sum )  {  
    int currentsum = arr[ 0 ] , begin = 0 , i ;  
   
    for ( i = 1 ; i <= n ; i++){  
        while ( currentsum > sum && begin < i - 1) {  
            currentsum = currentsum - arr[ begin ] ;  
            begin++ ;  
        }  
        if ( currentsum == sum ){  
            cout<<" Subarray indexes range " << begin << " and " << i - 1 << endl ;  
            return 1 ;  
        }  
        if (i < n)  
            currentsum = currentsum + arr[ i ] ;  
    }  
    cout << "NOT Found " << endl ;  
    return 0 ;  
}  
 
 
int main(){
    int n = 6;
    int a[6] = {2,3,7,10,15,16};
    int sum = 0;
    subarray(a,n,sum);
    return 0;
}
