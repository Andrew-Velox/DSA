#include <bits/stdc++.h>
using namespace std;

int chk_kth_itm_on_or_off(int kth_item,int kth_time){
    
    return (kth_item >> kth_time) & 1;

}

int main(){

    cout << chk_kth_itm_on_or_off(44,3) << endl; // 1
    cout << chk_kth_itm_on_or_off(44,4) << endl; // 0

    return 0;
}