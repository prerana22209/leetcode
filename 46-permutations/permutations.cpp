class Solution {
public:

    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp){
        if(nums.size()==0){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int c=nums[i];
            nums.erase(nums.begin() + i);
            temp.push_back(c);
            solve(nums,res,temp);
            temp.pop_back();
            nums.insert(nums.begin() + i, c);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums, res, temp);
        return res;
    }
};