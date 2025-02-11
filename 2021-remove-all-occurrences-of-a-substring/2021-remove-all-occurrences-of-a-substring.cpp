class Solution {
public:
    void solve(string& s,string& part){
        if(s.find(part)==string::npos){
            return;
        }
        s.erase(s.find(part),part.length());
        solve(s,part);
    }
    string removeOccurrences(string s, string part) {
        solve(s,part);
        return s;
    }
};