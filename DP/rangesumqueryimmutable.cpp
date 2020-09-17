// Range Sum Query - Immutable 

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size()==0)  return;
        pre.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            pre.push_back(nums[i]+pre[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)    return pre[j];
        else        return (pre[j]-pre[i-1]);        
    }
    private:
        vector<int> pre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */