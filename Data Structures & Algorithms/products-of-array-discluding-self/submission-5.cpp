class Solution{
        public:
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int>result;
        int i,j=0;
        for(i=0;i<nums.size();i++){
            
            int results =  1;
            for(int j=0;j<nums.size();j++){
                
                
                if(i==j){
                    continue;
                }
                results*=nums[j];
            }
            result.push_back(results);
        
        }
        return result;
    
    
    
    
    
    
    }
};
