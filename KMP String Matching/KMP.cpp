#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define dbg(x...)
#endif

// -----------------O(s1+s2) -> length------------------- //
void computeLPSArray(string pat,ll M,ll *lps){
    ll len=0;
    lps[0]=0;
    ll i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }

        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}


void KMPSearch(string pat,string txt){
    ll M=pat.size();
    ll N=txt.size();

    ll lps[M];

    computeLPSArray(pat,M,lps);

    ll i=0,j=0;

    while(i<N){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==M){
            cout << "Found Pattern at index: " << i-j << endl;
            j=lps[j-1];
        }

        else if(i<N && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string pat="AABA";
    string txt="AABAACAADAABAABA";

    KMPSearch(pat,txt);
    return 0;
}
