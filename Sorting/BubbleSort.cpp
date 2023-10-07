#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int array[]={23, 65, 15, 43, 10, 25, 35, 42, 18};

    int array_size=(sizeof(array)/sizeof(array[0]));

    int count = 1;
    while(count<array_size){
        for(int x=0; x<array_size-count; x++){
            if(array[x]>array[x+1]){
                int temp = array[x];
                array[x] = array[x+1];
                array[x+1]=temp;

            }
        }
        count++;
    }

    for(int x=0; x<array_size; x++){
        cout << array[x] << " ";
    }
    return 0;
}