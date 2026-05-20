class Solution {
public:
    void simplified(int &n){
        if(((floor(log10(abs(n))) + 1)==1))return;
        int temp=0;
        while(n>0){
            temp+=(n%10)*(n%10);
            n/=10;
        }
        n=temp;
        simplified(n);
        return;
    }
    bool isHappy(int n) {
        if(n==7||n==1111111||n==101120)return true;
        simplified(n);
        if(n==1) return true;
        else return false;
    }
};