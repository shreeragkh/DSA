#include<iostream>
#include<vector>
using namespace std;
class singleNumber
{
public:
    int singleNum(vector<int>& num){
        int ans=0;
        for(int val:num){
            ans^=val;
        }
        return ans;
    }
};
int main(){
    vector<int> num;
    singleNumber sn;
    int a;
    cout<<"Enter the number to push to vector (input -1 to exit):"<<endl;
    while(true){
        cin>>a;
        if(a==-1){
            break;
        }
        num.push_back(a);
    }
    cout<<sn.singleNum(num)<<endl;
}
