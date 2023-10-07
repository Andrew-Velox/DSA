#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int x=low; x<high; x++){
        if(arr[x] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[x];
            arr[x] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high){

    if(low<high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int array[6]={6, 3, 9, 5, 2, 8};
    int size = 6;

    quickSort(array, 0, size-1); 

    for(int x=0; x<size; x++){
        cout << array[x] << " ";
    }
    cout << endl;
 
    return 0;
} 