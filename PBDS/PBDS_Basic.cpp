#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less/*less_equal=multiset*/<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    vector<ll> v = {1,-2,4,2,7,3,4,6,8,9,4,2};
    pbds<ll> pb;
    for(auto val: v){
        pb.insert(val);
    }



    for(auto val: pb) cout << val << " ";
    cout << endl << endl;

    pb.erase(pb.find(4));
    cout << "After Erase: ";
    for(auto val: pb) cout << val << " ";
    cout << endl;

    int gets = pb.order_of_key(4);// how many values are before 4 
    cout << "Values before 4: " << gets << endl;

    auto value = pb.find_by_order(5); // FIND the VALUE of index 5, it will return ITERATOR
    cout << "Value of Index 5: " << *value << endl << endl; // printing VALUE using difference 


    // we cant erase value from less_equal(multiset) pbds, that why we have to take input as pair....
    cout << "Pair PBDS: " << endl; 
    pbds<pair<ll,ll>> pbpr;
    pbpr.insert({1,0});
    pbpr.insert({2,1});
    pbpr.insert({4,2});
    pbpr.insert({2,3});
    pbpr.insert({7,4});


    for(auto val: pbpr){
        cout << "\t " << val.first << " " << val.second << endl;
    }
    cout << endl;

    pbpr.erase(pbpr.find({4,2})); // erasing value.......

    cout << "After Erase: " << endl; 
    for(auto val: pbpr){
        cout << "\t " << val.first << " " << val.second << endl;
    }
    
    
    int va = pbpr.order_of_key({7,4});
    cout << va <<  endl;
    auto in = *pbpr.find_by_order(1);
    cout << in.first << " " << in.second << endl;


    return 0;
}

/*

Outputs:


-2 1 2 3 4 6 7 8 9 

After Erase: -2 1 2 3 6 7 8 9 
Values before 4: 4
Value of Index 5: 7

Pair PBDS: 
	 1 0
	 2 1
	 2 3
	 4 2
	 7 4

After Erase: 
	 1 0
	 2 1
	 2 3
	 7 4
3
2 1

*/
