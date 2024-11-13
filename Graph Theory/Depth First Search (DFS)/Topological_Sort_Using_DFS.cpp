// https://codeforces.com/gym/102219/problem/J
#include <bits/stdc++.h>
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define dbg(x...)
#endif

#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define ll long long
#define pb push_back
#define endl '\n'


stack<char> st;
bool visited[100];
bool path[100];
bool cycle;

vector<ll> adj_list[100];
void dfs(ll s){
    visited[s]=true;
    path[s]=true;

    for(auto val: adj_list[s]){
        if(path[val]) cycle=true;
        if(!visited[val]){
            dfs(val);
        }
    }
    path[s]=false;
    st.push(s+'A');
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  
    map<char,ll> mp;
    for(int x=0; x<5; x++){
        string s; cin >> s;
        if(s[1]=='<') swap(s[0],s[2]);

        adj_list[s[0]-'A'].pb(s[2]-'A');
    }


    for(char x='A'; x<='E'; x++){
        if(!visited[x-'A']) dfs(x-'A');
    }

    if(cycle) cout << "impossible" << endl;
    else{
        vector<char> ans;
        while(!st.empty()){
            ans.pb(st.top());
            st.pop();
        }
        rev(ans);
        for(auto val: ans) cout << val;
        cout << endl;
    }
    return 0;
}

/* 
input:
D>B
A>D
E<C
A>B
B>C
output: ECBDA
*/
