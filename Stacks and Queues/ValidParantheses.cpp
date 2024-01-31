#include<iostream>
#include<stack>
using namespace std;
stack < char > st;
bool isValidParenthesis(string s)
{
    for(auto it : s){
        if(it == '(' || it == '[' || it == '{') {
            st.push(it);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{')) 
            { 
                continue;
            }
            else 
            {
                return false;
        }
    }
    }
    return st.empty();
}

int main(){
    string str;
    cin>>str;
    cout<<isValidParenthesis(str);
    return 0;
}