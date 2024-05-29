#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size){

    //----------------//Explain for the first loop//-------------//


    // if we use an array like this [3,2,4,6,12]
                                            //1 2 3 4    
    for(int x=1; x<size; x++){ // start form [2,4,6,12] 
        int temp = arr[x]; // temp is 2
        int y = x-1; // y = 0 , 0 index = 3

        //for(y=x-1; y>=0; y--) //if we use for loops insted.

        while(y>=0){ // here y=0
            if(arr[y]>temp){ // if arr[y]=3 whice is begger then temp(temp=2),
                //shift arr[y] value to 1 step right
                arr[y+1] = arr[y]; // now arr[y+1] = 3 & arr[y] = 3 & temp = 2 {3,3,4,6,12}
            }

            else{ // it will not work
                //stop
                break;
            }
            y--; // y = -1 and first loop ends here.
        }
        arr[y+1] = temp; // now arr[y+1](index=0) = 2 {2,3,4,6,12}
    }

    // And thats how insertionSort works ;)

    //--------for print------//
    for(int x=0; x<size; x++){
        cout << arr[x] << " ";
    }
}

int main(){
   /*  int size;
    cin >> size;
    int array[size];
    
    for(int x=0; x<size; x++){
        cin >> array[x];
    }
 */
    // if you want to take input remove the comments and delete this two lines below.

    int array[]={10, 5, 15, 12, 8, 1, 18, 20, 3};
    int size = sizeof(array)/sizeof(array[0]);

    insertionSort(array,size);
    cout << endl;
    return 0;
}
