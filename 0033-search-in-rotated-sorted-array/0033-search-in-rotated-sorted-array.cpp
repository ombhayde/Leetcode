class Solution {
public:

    int findPivot(vector<int> v){
        int s=0;
        int e=v.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(s==e){
                return s;
            }
            if(mid-1>=0 && v[mid]<v[mid-1]){
                return mid-1;
            }
            else if(mid+1<v.size() && v[mid]>v[mid+1]){
                return mid;
            }else if(v[s]>v[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }

    int binarySearch(vector<int> nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(target==nums[mid]){
                return mid;
            }else if(target>nums[mid]){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums);
        int ans=-1;
        if(target>=nums[0]&&target<=nums[pivot]){
            ans=binarySearch(nums,0,pivot,target);
        }else{
            ans=binarySearch(nums,pivot+1,nums.size()-1,target);
        }
        return ans;
    }
};