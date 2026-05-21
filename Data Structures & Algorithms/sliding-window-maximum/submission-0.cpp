class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
    vector<int>result;
    for(int i=0;i<nums.size();i++){

        mp[nums[i]]++;
        if(i>=k){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
        }
        if(i>=k-1){

            int maxi = INT_MIN;
            for(auto it:mp){

                maxi=max(maxi,it.first);

            }

            result.push_back(maxi);
        }
    }
        return result;
    }
};
