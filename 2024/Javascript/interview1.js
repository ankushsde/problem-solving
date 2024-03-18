let str = "assistent"
 
function findOccurence(str){
    let mp = new Map()
    let n = str.length
    let ans;
    let cnt = 0; 
    
    for(let i = 0; i<n;i++){
        mp.set(str[i],(mp.get(str[i]) || 0) +1 )
        if(cnt<mp.get(str[i])){
            ans = str[i]
            cnt = mp.get(str[i])
        }
    }
    return ans
}

console.log(findOccurence(str))

let s = " this is a blue sky "
function reverseWords(s){
    s = s.split(' ')
    let res= []
    for(let i = s.length - 1; i>=0; i--){
        if(s[i]!= '') res.push(s[i])
    }
    return res.join(' ')
}
console.log(reverseWords(s))

function primeNumbers(num){
    let isPrime = true
    if (num === 1 ){
        console.log('1 is niether prime nor composite')
    }
    else if( num > 1 ){
    for(let i = 2; i<num; i++){
        if(num % i == 0){
            isPrime = false;
            break;
        }
    }
  }
  return isPrime ? `${num} is prime ` : `${num} is not prime `
}


console.log(primeNumbers(24))

//component mounting and unmounting eg: 

useEffect(()=>{
    console.log("Component Mounted")

    return () =>{
      console.log('Component Unmounted')
    }

  },[])

  class MyComponent extends Component {
    componentDidMount() {
      console.log('Component mounted');
    }
  
    componentWillUnmount() {
      console.log('Component unmounted');
    }
}