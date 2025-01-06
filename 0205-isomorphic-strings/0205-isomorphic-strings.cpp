class Solution {
public:

    void mapping(string& str){
        char start='a';
        char mapping[300]={0};
        for(auto ch:str){
            mapping[ch]=start;
            start++;
        }
        for(int i=0;i<str.length();i++){
            str[i]=mapping[str[i]];
        }
    }
    bool isIsomorphic(string s, string t) {
        mapping(s);
        mapping(t);
        if(s==t){
            return true;
        }else{
            return false;
        }
    }
};