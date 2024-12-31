class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto ch:nums){
            umap[ch]++;
        }
        for(auto it:umap){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};