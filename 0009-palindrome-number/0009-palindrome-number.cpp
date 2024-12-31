class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        int ans=0;
        if(x<0){
            return false;
        }
        while(temp!=0){
            if(ans<INT_MAX/10){
                ans=ans*10+(temp%10);
                temp/=10;
            }else{
                break;
            }
        }
        if(x==ans){
            return true;
        }else{
            return false;
        }
        
    }
};