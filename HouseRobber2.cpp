class Solution {
public:
    int rob(vector<int>& nums) 
    {
         vector<int> dp1(nums.size(),0);
         vector<int> dp2(nums.size()+1,0);
        
         if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];
         if(nums.size()==2)
            return max(nums[0], nums[1]);
        
         dp1[0]=nums[0];
         if(nums.size()>1)
            dp1[1]=max(dp1[0], nums[1]);
         
        for(int i=2; i<nums.size()-1; i++)
        {
            dp1[i]=max(dp1[i-1], dp1[i-2]+nums[i]);     
        }
        
        dp2[1]=nums[1];
        if(nums.size()>1)
            dp2[2]=max(dp2[1], nums[2]);
        
        for(int i=3; i<nums.size(); i++)
        {
            dp2[i]=max(dp2[i-1], dp2[i-2]+nums[i]);     
        }
        
        cout<<dp1[nums.size()-2]<<" "<<dp2[nums.size()-1];
        return max(dp1[nums.size()-2], dp2[nums.size()-1]);
        
    }
};