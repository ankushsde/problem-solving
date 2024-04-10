void deleteFromHeap() {
 arr[1] = arr[n];
 size - - ; 

 int i = 1; 
  while( i < size){
 int leftIndex = 2*i;
 int rightIndex = 2*i + 1; 
 
 if(leftIndex < size && arr[i] < arr[leftIndex]){
 swap(arr[i], arr[leftIndex]);
 i = leftIndex;
}

else if(rightIndex < size && arr[i] < arr[rightIndex]){
 swap(arr[i],arr[rightIndex]);
i = rightIndex;
}

else{
 return;
}

} 


}

h.deleteFromHeap();
