#include <stack>
#include <string>
#include<iostream>
using namespace std;

class MinRemovalForValidParenthesis
{
    stack<int> st;
public:
    string MinRemovels(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else{
                    s[i]='*';
                }
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};
int main(){
    MinRemovalForValidParenthesis mr;
    string s;
    cout<<"Enter a valid parenthesis:"<<endl;
    cin>>s;
    cout<<mr.MinRemovels(s)<<endl;
    return 0;
}
