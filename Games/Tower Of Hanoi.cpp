#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


void tower_of_hanoi(ll n, string beg, string end, string aux){ // A C B
    if(n==0) return;

    tower_of_hanoi(n-1,beg,aux,end); // A B C
    cout << beg << " -> " << end << endl;
    tower_of_hanoi(n-1,aux,end,beg); // B C A
}



int main(){
    
    ll n; cin >> n;
    tower_of_hanoi(n,"BEG","END","AUX"); // A C B

    return 0;
}

/* 

input:
4

output:
BEG -> AUX
BEG -> END
AUX -> END
BEG -> AUX
END -> BEG
END -> AUX
BEG -> AUX
BEG -> END
AUX -> END
AUX -> BEG
END -> BEG
AUX -> END
BEG -> AUX
BEG -> END
AUX -> END 

*/
