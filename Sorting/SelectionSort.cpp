#include <bits/stdc++.h>
using namespace std;

void SelectionShort(int arr[], int size){
    for(int x=0; x<size-1; x++){
        for(int y=x+1; y<size; y++){
            if(arr[y]<arr[x]){ //15<23
                //cout << arr[y] << " ";
                int temp = arr[y]; // temp = 15
                arr[y]=arr[x]; // 15 = 23
                arr[x]=temp; // 23 = 15 arrays index position changed.
                
            }
        }
        cout << arr[x] << endl; 
    }
    //for(int x=0; x<size; x++){
    //    cout << arr[x] << " ";
   // }
}

int main(){
    //int n;
    //cout << "How many Numbers: ";
    //cin >> n;
    int array[]={10, 5, 2, 8, 7};

    int array_size = (sizeof(array)/sizeof(array[0])); // or You can just use (n) value.
    //for(int x=0; x<array_size; x++){
        //cin >> array[x];
    //}
    SelectionShort(array, array_size);
    return 0;
}