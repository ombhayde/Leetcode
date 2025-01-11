class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t){
        //     return true;
        // }else{
        //     return false;
        // }

        int mapping1[256]={0};

        for(auto ch:s){
            mapping1[ch]++;
        }
        for(auto ch:t){
            mapping1[ch]--;
        }
        for(int i=0;i<256;i++){
            if(mapping1[i]!=0){
                return false;
            }
        }
        return true;
    }
};