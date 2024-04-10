//Heapify Algorithm

void Heapify(int arr[], int n, in i){


int largest = i ;
int left = 2*i;
int right = 2*i +1;

if(left<n && arr[largest]<arr[left]) {
 largest = left;
}
if(right< n&& arr[largest] < arr[right]){
 largest = right;
}
if(largest!=i){
 swap(arr[largest],arr[i]);
 heapify(arr,n,largest);
}
}

int arr[6] = {-1,53,54,52,50}
for( int i = n/2; i>0;i - - ; ){
  heapify(arr,n,i)
} 