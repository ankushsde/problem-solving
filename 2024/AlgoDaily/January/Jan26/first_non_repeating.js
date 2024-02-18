function firstNonRepeat(str, i,j){
    str = str.split('')

    for( i = 0; i<str.length; i++){
        for ( j=0;j<str.length;j++){
            if(i==j){
                continue
            }
            if(str[i]==str[j]){
                break
            }
        }
        if(j==str.length){
            return str[i]
        }
    }
 
}
let i, j;

console.log(firstNonRepeat('asdfsdafdasfodfsafnnunl',i,j))