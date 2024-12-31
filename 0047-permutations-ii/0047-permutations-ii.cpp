class Solution {
public:
    
    void solve(vector<int>& nums,vector<vector<int>>& ans,int s){
        if(s==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool> u;
        for(int i=s;i<nums.size();i++){
            if(u.find(nums[i])!=u.end()){
                continue;
            }
            u[nums[i]]=true;
            swap(nums[i],nums[s]);
            solve(nums,ans,s+1);
            swap(nums[i],nums[s]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};