#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int chk_kth_bit_is_on_or_off(int kth_bit, int kth_time){
    return (kth_bit >> kth_time) & 1;
}

int turn_on_kth_bit(int digit, int kth_time/*bit*/){
    return (digit | (1 << kth_time));
}

int turn_off_kth_but(int digit, int kth_time /*bit*/){
    return (digit & (~ (1 << kth_time)));
}

int toggle_kth_bit(int digit, int kth_time){
    return (digit ^ ( 1 << kth_time));
}


void chk_how_many_on_and_off(int digit){

    for(int k=0; k<=31; k++){
        if(chk_kth_bit_is_on_or_off(digit,k)){
            cout << 1 << " ";
        }

        else cout << 0 << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    // chk_how_many_on_and_off(44); 

    // cout << turn_on_kth_bit(44,4) << endl; // 60
    // cout << turn_off_kth_but(44,3) << endl; // 36
    cout << toggle_kth_bit(44,3) << endl; // 36

    return 0;
}