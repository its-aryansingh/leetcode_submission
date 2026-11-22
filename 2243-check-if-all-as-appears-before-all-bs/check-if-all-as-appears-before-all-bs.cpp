class Solution {
public:
    bool checkString(string s) {
        bool flag = false;

        for(auto ch : s){

            
            if( ch =='a' && flag == true){
                flag = false;
               return flag;

            }
            else if (ch =='b'){
                flag = true;
            }
           
        }
        return true;

        
    }
};