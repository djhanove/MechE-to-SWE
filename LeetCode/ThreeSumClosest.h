class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        if(nums.size() < 3)
            return 0;
        std::sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for(size_t i = 0; i < nums.size(); i++) {
            int inter = target - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back) {
                
                if(abs(nums[i] + nums[front] + nums[back] - target) < abs(sum - target)) 
                    sum = nums[i] + nums[front] + nums[back];
                if(nums[front] + nums[back] < inter) front++;
                else if (nums[front] + nums[back] > inter)  back--;
                else
                    return nums[i] + nums[front] + nums[back];
            }     
        }
        return sum;
        
    }  
};
