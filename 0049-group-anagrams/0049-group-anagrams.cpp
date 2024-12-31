class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto ch:strs){
            string s=ch;
            sort(s.begin(),s.end());
            mp[s].push_back(ch);
        }

        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};