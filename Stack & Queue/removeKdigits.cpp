#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
using std::string;
using std::stack;

class removeKdigits
{
public:
    string removeKdigit(string num, int k){
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while (!st.empty() &&k>0 && st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && st.size()>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(!ans.empty() && ans.front()=='0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};
int main(){
    removeKdigits r;
    string str;
    int k;
    cout<<"Enter the input value:"<<endl;
    cin>>str;
    cout<<"Enter the number of digits to remove:"<<endl;
    cin>>k;
    cout<<"The new number after removing "<<k<<" digits is:"<<r.removeKdigit(str,k)<<endl;
}

