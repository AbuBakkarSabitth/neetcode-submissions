class Solution{

public:
    int trap(vector<int>&height){

    int left=0,right=height.size()-1;
    int left_max=0,right_max=0;
    int water =0;
    while(left<right){

        left_max= max(left_max,height[left]);
        right_max = max(right_max,height[right]);
        if(left_max < right_max){
            water+=left_max - height[left];
            left++;
        }
        else{
            water+=right_max - height[right];
            right--;
        }
    }
    return water;
    }

    };