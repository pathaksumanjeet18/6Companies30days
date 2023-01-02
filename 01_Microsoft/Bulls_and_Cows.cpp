#include <bits/stdc++.h>
using namespace std;
string getHint(string secret, string guess) {
        string ans = "";
        int c = 0;
        for(int i = 0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                c++;
                secret[i] = 'X';
                guess[i] = 'X';
            }
        }
        ans += to_string(c);
        ans += "A";
        unordered_map<int,int> mpp;
        unordered_map<int,int> mpp1;
        for(int i = 0;i<secret.size();i++){
            if(secret[i]=='X'){
                continue;
            }
            else{
                int x = int(secret[i])-48;
                mpp[x]++;
            }
        }
        for(int i = 0;i<guess.size();i++){
            if(guess[i]=='X'){
                continue;
            }
            else{
                int x = int(guess[i])-48;
                mpp1[x]++;
            }
        }
        int w = 0;
        for(auto it: mpp){
            int x = it.first;
            if(mpp1.find(x)!=mpp1.end()){
                w += min(mpp[x],mpp1[x]);
            }
        }
        ans += to_string(w);
        ans += "B";

        return ans;
    }
    int main(){

        string secret = "1123";
        string guess = "0111";
        cout<<getHint(secret,guess);


        return 0;
    }