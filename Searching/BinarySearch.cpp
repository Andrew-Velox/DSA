#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int size, int searchNumber){
    int low=0;
    int high=size-1;
    
    while(low<=high){
        int mid = (low+high)/2; // Getting mid Number of the array.
        if(searchNumber ==  array[mid]){ // SearchNuumber == input Number.
            return mid;
            cout << mid << endl;
        }
        else if(searchNumber > array[mid]){
            low = mid + 1;
            cout << mid << endl;
        }
        else{
            high = mid - 1;
            cout << mid << endl;
        }
    }
    return -1;
}

int main(){
    int a[] = {1,4,6,7,10,19,22,23,30,35,39,46,49,50,52,55,61,67,70,71};
    int array_size = (sizeof(a)/sizeof(a[0]));

    int n;
    cout << "Enter the Number You Want to search: ";
    cin >> n;

    int result = binarySearch(a, array_size, n);

    if (result >=0) {
        cout << "Element " << a[result] << " found at index " << result << endl;
    }
    else{
        cout << "Element " << n << " Not found"<< endl;
    }
    return 0;
}