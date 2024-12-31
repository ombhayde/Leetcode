class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int>& out,int s){
        if(target==0){
            ans.push_back(out);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=s;i<candidates.size();i++){
            out.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,out,i);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(candidates,target,ans,out,0);
        return ans;
    }
};