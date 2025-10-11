#include<iostream>
#include<vector>
using namespace std;
class majorityElement
{
public:
    int  Majority(vector<int> nums){
        int freq=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0){
                ans=nums[i];
            }if(freq==nums[i]){
                freq++;
            }else{
                freq--;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans) count++;
        }
        if(count>nums.size()/2) return ans;
        return -1;
    }
};

int main(){
    vector<int> nums;
    majorityElement abj;
    cout<<"Enter the elements in array (input -1 to exit): ";
    int input;
    while(cin>>input &&input!=-1){
        nums.push_back(input);
    }
    cout<<"Majority Element is: "<<abj.Majority(nums)<<endl;
    return 0;
}