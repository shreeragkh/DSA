#include<iostream>
#include<stack>
using namespace std;
class basicCalculator
{
public:
int number=0;
int sign=1;
int result=0;
stack<int> st;
 int calculator(string s){
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(isdigit(c)){
            number=number*10+(c-'0');
        }
        else if(s[i]=='+'){
            result+=sign*number;
            number=0;
            sign=1;
        }
        else if(s[i]=='-'){
            result+=sign*number;
            number=0;
            sign=-1;
        }
        else if( s[i]=='('){
            st.push(result);
            st.push(sign);
            result=0;
            sign=1;
        }
        else if(s[i]==')'){
         result+=sign*number;
         number=0;
         int prevSign=st.top();st.pop();
         int prevResult=st.top();st.pop();
         result=prevResult+prevSign*result;   
        }
    }
    result+=sign*number;
    return result;
 }
};
int main(){
    basicCalculator bs;
    string str;
    cout<<"Enter the string:"<<endl;
    cin>>str;
    int result=bs.calculator(str);
    cout<<"Result:"<<result<<endl;
    return 0;
}


