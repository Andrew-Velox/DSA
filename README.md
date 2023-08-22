[![Stargazers][stars-shield]][stars-url]
[![Forks][forks-shield]][forks-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

[forks-shield]: https://img.shields.io/github/forks/Andrew-Velox/DSA.svg?style=for-the-badge
[forks-url]: https://github.com/Andrew-Velox/DSA/network/members
[stars-shield]: https://img.shields.io/github/stars/Andrew-Velox/DSA.svg?style=for-the-badge
[stars-url]: https://github.com/Andrew-Velox/DSA/stargazers
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/mohabbat69

## Data Structures and Algorithms (DSA) in c++

- [Table of Contents](#table-of-contents)
- [Searching](#searching)
- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- [Shorting](#shorting)
- [Selection Sort](#selection-sort)
- [Bubble Sort](#bubble-sort)
- [Insertion Sort](#insertion-sort)


<h1>Searching</h1>

### Linear Search
 Linear search is a sequential searching algorithm where we start from one end and check every element of the list until the desired 
 element is found.

 Here is the code in C++.

  ``` c++
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
  ```

<!--

<details> <summary> smash me </summary>

<b>1. Problem A</b>

<details> <summary> Code(C++) </summary>

```c++
#include<iostream>
using namespace std;

int main() {
  char name[100]; // considering the name has at most 100 characters
  cin >> name; // take the name as input
  cout << "Hello, " << name << '\n'; // output in the correct format
  return 0;
}
```

</details>
<br>-->

### Binary Search

 Binary Search is a searching algorithm for finding an element's position in a sorted array.
 In this approach, the element is always searched in the middle of a portion of an array.
 
 Binary search can be implemented only on a sorted list of items. If the elements are not sorted already, we need to sort them first.

 Here is the code in C++.

  ``` c++
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
  ```
Without using separated function.

<details> <summary> smash me </summary>


  ``` c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int array[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100};
    int n,ans=-1;
    cout << " Enter Number: ";
    cin >> n;
    int array_size = (sizeof(array)/sizeof(array[0]));
    int low=0,high=array_size-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(n==array[mid]){
            ans = mid;
            break;
        }
        else if(n<array[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    if(ans>=0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
  ```
</details>

<h1>Shorting</h1>

### Selection Sort

 Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.

 Here is the code in C++.

  ``` c++
#include <bits/stdc++.h>
using namespace std;

void SelectionShort(int arr[], int size){
    for(int x=0; x<size-1; x++){
        for(int y=x+1; y<size; y++){
            if(arr[y]<arr[x]){ //15<23
                int temp = arr[y]; // temp = 15
                arr[y]=arr[x]; // 15 = 23
                arr[x]=temp; // 23 = 15 arrays index position changed.
            }
        }
    }
    for(int x=0; x<size; x++){
        cout << arr[x] << " ";
    }
}

int main(){
    //int n;
    //cout << "How many Numbers: ";
    //cin >> n;
    int array[]={23, 65, 15, 43, 10, 25, 35, 42, 18};

    int array_size = (sizeof(array)/sizeof(array[0])); // or You can just use (n) value.
    //for(int x=0; x<array_size; x++){
        //cin >> array[x];
    //}
    SelectionShort(array, array_size);
    return 0;
}
  ```

### Bubble Sort

 Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.

Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a bubble sort.
 Here is the code in C++.

  ``` c++
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
  ```

<!--


  Here is the code for the problem in C++.

  ``` c++
  #include<bits/stdc++.h>
  using namespace std;

  int main() {
    long long n; cin >> n;
    cout << 25 << '\n';
    return 0;
  }
  ```

### The Ultimate Question: Why should I start Competitive Programming?

  
### What Progress is Really Like--->
  
