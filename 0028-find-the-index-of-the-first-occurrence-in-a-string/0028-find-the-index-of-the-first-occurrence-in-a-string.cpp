class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=string::npos){
            int find=haystack.find(needle);
            return find;
        }else{
            return -1;
        }
    }
};