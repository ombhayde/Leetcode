class Solution {
public:
    bool solve(vector<int>& counts,vector<int>& quantity,int curr){
        if(curr==quantity.size()){
            return true;
        }

        for(int i=0;i<counts.size();i++){
            if(counts[i]>=quantity[curr]){
                counts[i]-=quantity[curr];
                if(solve(counts,quantity,curr+1)){
                    return true;
                }
                counts[i]+=quantity[curr];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num:nums)
            countMap[num]++;
        vector<int> counts;
        for(auto it:countMap)
            counts.push_back(it.second);
        sort(quantity.rbegin(),quantity.rend());
        return solve(counts,quantity,0);
    }
};