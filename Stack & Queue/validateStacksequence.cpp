#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class validateStacksequence
{
public:
    stack<int> st;
    bool validateStack(vector<int> pushed,vector<int> popped){
        int j=0;
        for(int i:pushed){
            st.push(i);
        
        while(!st.empty() && st.top()==popped[j]){
            st.pop();
            j++;
        }
    }
        return st.empty();
    }
};
int main(){
    vector<int> pushArr;
    vector<int> popArr;
    int i;
    validateStacksequence val;
    cout<<"Enter the elemnets to push into stack (input -1 to exit):"<<endl;
    while (true)
    {
        cin>>i;
        if(i==-1){
            break;
        }
        else{
            pushArr.push_back(i);
        }
    }
    cout<<"Enter the popped sequence (input -1 to exit):"<<endl;
    while (true)
    {
        cin>>i;
        if(i==-1){
            break;
        }
        else{
            popArr.push_back(i);
        }
    }
    if(val.validateStack(pushArr,popArr)){
        cout<<"Valid stack"<<endl;
    }
    else{
        cout<<"InValid stack"<<endl;
    }
    return 0;
}