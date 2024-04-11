approach 2 : using heap ;
// step 1 : insert first k elements in the max heap
//step 2  : for rest of the elements from k to n-1, if(arr[i]<pq.top()){
// pq.top();
// pq.push(arr[i]);
// } 

int ans = pq.top();

priority_queue<int> pq;
for(int i = 0; i<k; i++){
pq.push(arr[i]);
}

for(int i = k ; i<=n; i++){
 if(arr[i]) < pq.top()){
  pq.pop();
  pq.push(arr[i]);
}
}
int ans = pq.top();
