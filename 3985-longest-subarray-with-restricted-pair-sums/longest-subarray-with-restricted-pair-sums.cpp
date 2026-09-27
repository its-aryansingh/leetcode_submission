typedef int ll; 
class Solution {
public:
    int maxSubarray(vector<int>& a) {
        ll n = a.size(); ll pi=0; 
        // for(ll i=0;i<=n-1;i++){
        //     ll freq[1001] = {0};
        //     ll result[1001] = {0};
        //     for(ll j=i;j<=n-1;j++){
                
        //         ll number = a[j]; 
        //         bool answer = true; 

        //         if(result[number]>=1){
        //             answer = false; 
        //         }
                
        //         for(ll l=1;l<=500;l++){
        //             if(freq[l]>=1){  
        //                 ll r = l + number;
        //                 result[r] = result[r] + freq[l];
        //                 if(freq[r]>=1){
        //                     answer = false;
        //                 }
        //             }
        //         }
        //         freq[a[j]] = freq[a[j]] + 1; 
        //         //[i.......j] 
        //         if(answer==true){
        //             pi = max(pi,j-i+1);
        //         }else{
        //             j = n+5;
        //         }
        //     }
        // }
        ll freq[1005] = {0};
        ll result[1005] = {0};
        bool answer = true; 
        for(int i = 0, j = 0; j < n; j++) {
        	
            //sum = sum + b[j]; //[............]
            ll number = a[j];
            if(result[number]>=1){
                    answer = false;
            }

            //now freq[] only contains data of range [i......j-1]

            for(ll l=1;l<=500;l++){
                if(freq[l]>=1){  
                    ll r = l + number;
                    result[r] = result[r] + freq[l];
                    if(freq[r]>=1){
                        answer = false;
                    }
                }
            }
            freq[a[j]] = freq[a[j]] + 1;
             //now freq[] only contains data of range [i......j]

           
            
            while (answer==false){
                //sum = sum - b[i];
                ll nr = a[i];

                freq[nr] = freq[nr] - 1;
                



                //now freq[] only contains data of range [i+1....j]
                for(ll l=1;l<=500;l++){
                	if(freq[l]>=1){  
                		ll r = l + nr;
                		result[r] = result[r] - freq[l];


                	}
                }

                answer = true; 
                for(ll l=1;l<=500;l++){
                    if(result[l]>=1 && freq[l]>=1){

                        answer = false; 
                    }
                }
                //answer = true;

                i++;
               
            }
            
            //this is true zone
            //count += (j - i + 1);
            pi = max(pi,j-i+1);
        }
        
        
        
        
        
        
        return pi; 
        
    }
};