#include <bits/stdc++.h>
using namespace std;

int linearSearch(int array[], int size, int serchNumber){
  for( int x=0; x<size; x++){
    if(serchNumber==array[x]){
      return x; // Returning Index position. (result = x)
    }
  }
  //int i =  -1;
  return -1; //otherwise it will return reslt = -1
}

int main(){
  int a[] = {1,4,6,7,10,19,22,23,30,35,39,46,49,50,52,55,61,67,70,71};
  /*To find the length of the array, you need to divide the total amount of memory by the size of one element - this method works because the array stores items of the same type.*/
  int len = sizeof(a) / sizeof(a[0]); // Calculate the size of the array.
  int n;
  cout << "Enter which Number You want to search: ";
  cin >> n;

  int result = linearSearch(a, len, n); // Passing The Values to linearSearch function.

  if(result>=0){
    cout << "The Number " << a[result] << " Was found at index positon: " << result << endl;
  }
  else{
    cout << "The Number " << n << " Was Not Found" << endl;
  }

  return 0;
}