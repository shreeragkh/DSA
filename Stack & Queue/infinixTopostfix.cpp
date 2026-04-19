#include<iostream>
#include<string>
#include<stack>
using namespace std;
class infinixTopostfix
{
public:
    int getPrecedence(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*'||c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infinixTopostfix_exp(string infinix){
        stack<char> operartionStack;
        string postfix="";
        for(int i=0;i<infinix.length();i++){
            char c=infinix[i];
            if(isalnum(c)){
                postfix+=c;
            }
            else if(c=='('){
                operartionStack.push(c);
            }
            else if(c==')'){
                while (!operartionStack.empty()&& operartionStack.top()!='(')
                {
                    postfix+=operartionStack.top();
                    operartionStack.pop();
                }
                if(!operartionStack.empty()){
                    operartionStack.pop();
                }
            }
            else{
                    while (!operartionStack.empty() && operartionStack.top()!='(' && getPrecedence(c)<=getPrecedence(operartionStack.top()))
                    {
                        postfix+=operartionStack.top();
                        operartionStack.pop();
                    }
                        operartionStack.push(c);
                }
        }
        while (!operartionStack.empty())
                {
                    postfix+=operartionStack.top();
                    operartionStack.pop();
                }
        return postfix;
    }
};
int main(){
    string infinix_exp;
    cin>>infinix_exp;
    infinixTopostfix obj;
    string postfix_exp=obj.infinixTopostfix_exp(infinix_exp);
    cout<<postfix_exp<<endl;
    return 0;
}

