#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int maxSum=INT_MIN, currSum=0;
        for(int val:nums){
            currSum+=val;
            maxSum=max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};
int main(){
    Solution sl;
    vector<int> nums;
    int val;
    cout<<"Enter the elements of the array (type 'end and enter' to finish):"<<endl;
    while(cin>>val){
        nums.push_back(val);
    }
    int result = sl.maxSubArray(nums);
    cout<<"Maximum Subarray Sum: "<<result<<endl;
    return 0;
}