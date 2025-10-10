#include<iostream>
#include<stack>
#include <string>
using namespace std;
class ValidParentheses
{
public:
    bool isValid(string s){
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if((c==')' && st.top()=='(') ||
                        (c=='}' && st.top()=='{') ||
                        (c==']' && st.top()=='[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main(){
    ValidParentheses vp;
    string str;
    cout<<"Enter a string:";
    cin>>str;
    if (vp.isValid(str))
    {
        cout<<"Valid string"<<endl;
    }
    else{
        cout<<"Invalid string"<<endl;
    }
    return 0;
}