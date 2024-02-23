#include <bits/stdc++.h>
#define ll long long
using namespace std;
// ----------------------Time Complexity----------------
// ------------------------ O(2^N)----------------------
int knapsack(int n, int weight[], int values[], int w){

    // base case
    if(n<0 || w==0) return 0;

  
    if(weight[n] <= w){
        // check by taking its value
        int opt1 = knapsack(n-1,weight,values, w-weight[n])+values[n];

        // check without taking its value
        int opt2 = knapsack(n-1,weight,values, w);

        return max(opt1,opt2); 
    }

    else{
        int opt2= knapsack(n-1, weight, values, w);
        return opt2;
    }

}

int main(){
    int n;
    cin >> n;

    int weight[n],values[n];
    for(int x=0; x<n; x++) cin >> weight[x];
    for(int x=0; x<n; x++) cin >> values[x];
    
    int w; cin >> w;
    cout << knapsack(n-1,weight,values,w) << endl;
    return 0;
}
