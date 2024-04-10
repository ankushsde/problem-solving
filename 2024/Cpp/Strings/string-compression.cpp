class Solution {
public:
    int compress(vector<char>& chars) {

        string res = "";
        char c = ' ';
        int i = 0;int count=0;
        while(i < chars.size()){
            
            if( c == ' '){
                c= chars[i];
                count++;
                res+=c;
            }else{

                if(chars[i] ==  c){

                    count++;

                }else{
                    if(count != 1){
                        res=res+to_string(count);
                    }
                    c = ' ';
                    count = 0;
                    continue;
                }
            }
            i++;
        }
        if(count != 1){
              res=res+to_string(count);
        }
        
        for(int i = 0 ; i<res.length() ; i++){
            chars[i] = res[i];
        }

        return res.length();        
    }
};