#include<iostream>
#include<vector>
using namespace std;

class ContainerWIthMostWater
{
public:
int maxArea(vector<int>& height){
    int maxWater=0;
    int lp=0,rp=height.size()-1;
    while(lp<rp){
      int  w=rp-lp;
      int h=min(height[lp],height[rp]);
      int currentWater=w*h;
      maxWater=max(maxWater,currentWater);
      height[lp]<height[rp]?lp++:rp--;
    }
    return maxWater;
}  
} ;
 int main(){
    vector<int> height;
    ContainerWIthMostWater cwmw;
    int a;
    cout<<"Enter the height to push to vector (input -1 to exit):"<<endl;
    while(true){
        cin>>a;
        if(a==-1){
            break;
        }
        height.push_back(a);
    }
    cout<<cwmw.maxArea(height)<<endl;
};

