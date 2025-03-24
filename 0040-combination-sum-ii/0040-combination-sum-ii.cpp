class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> output,int s){
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=s;i<candidates.size();i++){
            if(i>s&&candidates[i]==candidates[i-1]){
                continue;
            }
            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,output,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates,target,ans,output,0);
        return ans;
    }
};