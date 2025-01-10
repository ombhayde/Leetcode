class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=2;
        if (n==1||n==2){
            return true;
        }
        while((pow(2,i))<=n){
            if ((n==(int(pow(2,i))))){
                return true;
            }
            i++;
        }
        return false;
    }
};