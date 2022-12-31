#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i]=="*"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x*y);
            }
            else if(tokens[i]=="/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y/x);
            }
            else if(tokens[i]=="+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x+y);
            }
            else if(tokens[i]=="-"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y-x);
            }
            else{
                int c = stoi(tokens[i]);
                st.push(c);
            }
        }
    return st.top();
}
int main(){

    vector<string> tokens{"2","1","+","3","*"};
    cout<<evalRPN(tokens);

    return 0;
}