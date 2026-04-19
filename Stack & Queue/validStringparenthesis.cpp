#include<iostream>
#include<stack>
#include<string>
using namespace std;
class validStringparenthesis
{
public:
bool validateString(string s){
    stack<int> open;
    stack<int> star;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            open.push(i);
        }
        else if(s[i]=='*'){
            star.push(i);
        }
        else{
            if (!open.empty())
            {
                open.pop();
            }
            else if (!star.empty())
            {
                star.pop();
            }
            else{
                return false;
            }
            
            
        }
    }
    while (!star.empty() && !open.empty())
    {
        if(open.top()<star.top()){
            open.pop();
            star.pop();
        }
        else{
            return false;
        }
    }
    return open.empty();
}
};
int main(){
    string str;
    validStringparenthesis vp;
    cout<<"Enter the string:"<<endl;
    cin>>str;
    if(vp.validateString(str)){
        cout<<"String is valid"<<endl;
    }
    else{
        cout<<"String is not valid"<<endl;
    }
    return 0;
}

