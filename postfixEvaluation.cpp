#include<iostream>
#include<string>
#include<cmath>
#include<stack>
using namespace  std;

class postfixEvaluation
{
public:
    int postfix_eval(string postfix){
        stack<int> st;
        for(int i=0;i<postfix.length();i++){
            char c=postfix[i];
            if(isdigit(c)){
                st.push(c-'0');
            }
            else{
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                switch (c)
                {
                case '+':
                    st.push(val1+val2);
                    break;
                case '-':
                    st.push(val1-val2);
                    break;
                case '*':
                    st.push(val1*val2);
                    break;
                case '/':
                    st.push(val1/val2);
                    break;
                case '^':
                    st.push(pow(val1,val2));
                    break;
                default:
                    break;
                }
            }
        }
        return st.top();
    }
};
int main(){
    string postfix;
    cin>>postfix;
    int result=postfixEvaluation().postfix_eval(postfix);
    cout<<result<<endl;
    return 0;
}

