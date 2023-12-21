[![Stargazers][stars-shield]][stars-url]
[![Forks][forks-shield]][forks-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

[forks-shield]: https://img.shields.io/github/forks/Andrew-Velox/DSA.svg?style=for-the-badge
[forks-url]: https://github.com/Andrew-Velox/DSA/network/members
[stars-shield]: https://img.shields.io/github/stars/Andrew-Velox/DSA.svg?style=for-the-badge
[stars-url]: https://github.com/Andrew-Velox/DSA/stargazers
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/mohabbat69

## Basic Data Structures and Algorithms (DSA) in c++
### Table of Contents
<!--- [Table of Contents](#table-of-contents)-->
- [Data Structures](#data-structures)
  - [Linked List](#linked-list)
    - [Singly Linked List](#singly-linked-list)  
    - [Doubly Linked List](#doubly-linked-list)  
  - [Stack](#stack)
  - [Queue](#queue)
- [Algorithms](#algorithms)
  - [Searching](#searching)
    - [Linear Search](#linear-search)
    - [Binary Search](#binary-search)
  - [Sorting](#sorting)
    - [Selection Sort](#selection-sort)
    - [Bubble Sort](#bubble-sort)
    - [Insertion Sort](#insertion-sort)
    - [Quick Sort](#quick-sort)


<h1>Data Structures</h1>

<h2>Linked List</h2>
A linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.<br></br>
<h3>Singly Linked List</h3>
Singly linked list can be defined as the collection of ordered set of elements. The number of elements may vary according to need of the program. A node in the singly linked list consist of two parts: data part and link part. Data part of the node stores actual information that is to be represented by the node while the link part of the node stores the address of its immediate successor.
<br></br>
 <details> <summary> Click here to See the complete Linked list code in C++ </summary>

  ``` c++
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void in_at_head(Node *&head, int val){
    Node *newNode= new Node(val); 
    newNode->next=head;       // first, point head with new node
    head=newNode;        //  thene update hade to new node
    cout << "\n\nEnserted At Head\n" << endl;
}


void in_at_tail(Node *&head,int val){
    Node *newNode = new Node(val);
    
    if(head==NULL){         // if head Null
        head=newNode; 
        cout << endl << endl << "Inserted At Head\n\n" << endl;
        return;
    }
    Node *tmp = head;       // we cannot change position of head

    while(tmp->next != NULL){      // go until found NULL
        tmp = tmp->next;
    }

    tmp -> next = newNode;          // now the NULL have newNodes Address
    cout << "\n\nEnserted At Tail\n" << endl;

}

void in_at_any_pos(Node *head,int v, int pos){
    Node *newNode = new Node(v);

    Node * tmp= head;
    for(int x=1; x<=pos-1; x++){        // go untill found the position
        tmp=tmp->next;
        if(tmp==NULL){
            cout << "\n\n Invalid Position \n\n";
            return;
        }
    }
    newNode->next=tmp->next;   // point newNode nxt to -> tmp nxt node 
    tmp->next=newNode;         // point tmp nxt to newNode

    cout << "\n\nInserted At position " << pos << endl << endl;
}

void delete_Node(Node *&head,int pos){

    if(pos==0){
        if(head==NULL){
            cout << "\n\n There is no Head.\n\n";
            return;
        }
        Node *deleteNode = head;
        head=head->next;
        delete deleteNode;
        cout << "\n\nHead Node Deleted. "<< endl << endl;
        return;
    }
    
    Node *tmp = head;
    for(int x=1; x<=pos-1; x++){    // go for the position
        tmp=tmp->next;
        if(tmp==NULL){
            cout << "\n\n Wrong Position\n\n";
            return;
        }
    }
    if(tmp->next==NULL){
        cout << "\n\n Wrong Position\n\n";
        return;
    }

    Node *deleteNode = tmp->next;       // store delete node
    tmp->next=tmp->next->next;  // connect tmp with 2nd next Node
    delete deleteNode;      // delete That Node
    cout << "\n\nNode Deleted of position " << pos << endl << endl;
}

void print(Node *head){
    Node *tmp = head;
    cout << endl << endl << "Your Linked List: ";
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp= tmp->next;
    }
    cout << endl << endl;
}

int main(){
    
    Node *head = NULL;
    while(1){

        cout << "1. Insert at Head." << endl;
        cout << "2. Insert at tail." << endl;
        cout << "3. Insert at any Position." << endl;
        cout << "4. Delete form Position." << endl;
        cout << "5. Print." << endl;
        cout << "6. Exit." << endl;
        cout << "Enter: ";
        int n; cin >> n;

        if(n==1){
            int v;
            cout << "Enter Value: ";
            cin >> v;
            in_at_head(head,v);
        }

        if(n==2){
            int v;
            cout << "Enter Value:";
            cin >> v;
            in_at_tail(head,v);
        }
        else if(n==3){
            cout << "Enter Value: ";
            int v;cin >> v;
            cout << endl << "Enter Position: ";
            int pos; cin >> pos;

            if(pos==0){
                in_at_head(head,v);
            }
            else in_at_any_pos(head,v,pos);
        }

        else if(n==4){
            cout << "Enter Position: ";
            int pos; cin >> pos;

            delete_Node(head,pos);
        }
        else if(n==5){
            print(head);
        }
        else if(n==6){
            break;
        }

    }
    return 0;
}
  ```
</details>


<h3>Doubly Linked List</h3>
 updating...
<br></br>
 <details> <summary> Click here to See the complete Linked list code in C++ </summary>
 ``` c++
 ```
 </details>

 
### Stack

Updating...
### Queue
Updating....

<h1>Algorithms</h1>

<h2>Searching</h2>

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
  /*To find the length of the array, you need to divide the total amount of memory by the
 size of one element - this method works because the array stores items of the same type.*/
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

<h2>Sorting</h2>

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

### Insertion Sort

 Insertion sort works similarly as we sort cards in our hand in a card game.

We assume that the first card is already sorted then, we select an unsorted card. If the unsorted card is greater than the card in hand, it is placed on the right otherwise, to the left. In the same way, other unsorted cards are taken and put in their right place.

Here is the code in C++.

  ``` c++
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size){

    //----------------//Explain for the first loop//-------------//


    //---if we use an array like this [3,2,4,6,12]---//
                                            //1 2 3 4    
    for(int x=1; x<size; x++){ // start form [2,4,6,12] 
        int temp = arr[x]; // temp is 2
        int y = x-1; // y = 0 , 0 index = 3 , arr[y] = 3

        //for(y=x-1; y>=0; y--) //if we use for loops insted.

        while(y>=0){ // here y=0
            if(arr[y]>temp){ // arr[y]=3 whice is begger then temp(temp=2),
                //shift arr[y] value to 1 step right
                arr[y+1] = arr[y]; // now arr[y+1] = 3 , now main array is like [3,3,4,6,12]
            }

            else{ // it will not work
                //stop
                break;
            }
            y--; // y = -1 and first loop ends here.
        }
        arr[y+1] = temp; // now arr[y+1](index=0) = 2 , now main array is like [2,3,4,6,12]
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
  ```

### Quick Sort

 QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

 Here is the code in C++.

  ``` c++
#include <bits/stdc++.h>
using namespace std;


// if you want to swap the value by using deferent function //

/* void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
} */

int partition(int arr[], int low, int high){
                        //low=0, hight=6

         // array = 6, 3, 9, 5, 2, 8 //
    //array index = 0  1, 2, 3, 4, 5 //


    int pivot = arr[high]; // [pivot = 8]
    int i = low-1; // i = -1(0-1) out of index

    //      low=0, high=8   //
    for(int x=low; x<high; x++){
                             //    first loop       |  2nd loop     |   3rd loop     |  4th loop       |  5th loop       |  6th loop      //
        if(arr[x] < pivot){  //  arr[0]=6 < pivot=8 | ar[1]=3 < p=8 |  ar[2]=9 > p=8 |  ar[3]=5 < p=8  |  ar[4]=2 < p=8  |  ar[5]=8 == p=8
            i++;             //   i = 0 (index)     | i = 1 (index) |    skip        |  i = 2          |  i = 3          |  skip   
            
            //swap(arr,i,x);
            // swap//           // 1st loop  |  2nd loop  |  4th loop  |  5th loop
            int temp = arr[i];  // temp=6    |   temp=3   |   temp=9   |   temp=9
            arr[i] = arr[x];    // 6<-->6    |   3<-->3   |   9<-->5   |   9<-->2
            arr[x] = temp;      // 6<-->6    |   3<-->3   |   5<-->9   |   2<-->9
        }

        //1st loop = 6, 3, 9, 5, 2, 8
        //2nd loop = 6, 3, 9, 5, 2, 8
        //3rd loop = 6, 3, 9, 5, 2, 8
        //4th loop = 6, 3, 5, 9, 2, 8
        //5th loop = 6, 3, 5, 2, 9, 8
    }

    //swap(arr, i+1, high);
    //         i = 3 + 1
    int temp = arr[i + 1];  // temp = 9
    arr[i + 1] = arr[high]; // 9<-->8
    arr[high] = temp;       // 8<-->9

    /* finaly the loop is = 6, 3, 5, 2, 8, 9     for first try we transfer all the 
    big numbers to the right & small numbers to the left from pivot number.*/

    return i + 1;  // return = 3+1 = 4

}


void quickSort(int arr[], int low, int high){
    // first condition we have to check that low is smaller then high.
    if(low<high){
        // getting pivod index, here low=0 & high=8
        int pi = partition(arr, low, high); // after passing this values,we get the pivot(8) index position pi=4

        quickSort(arr, low, pi-1);  // sort the small elements from the pivot, so 4-1
        quickSort(arr, pi+1, high); // sort the big elements from the pivot, so 4+1
    }
}

int main(){
    //int n;
    int array[6]={6, 3, 9, 5, 2, 8};

    int size = 6;//(sizeof(array)/sizeof(array[0]));

    /* low will be fast = 0, and high will be the last 
    index number last = size-1 */
    quickSort(array, 0, size-1); 

    for(int x=0; x<size; x++){
        cout << array[x] << " ";
    }
    cout << endl;
    //cout << size << endl;
    return 0;
} 

  ```
Without Comments.

<details> <summary> smash me </summary>


  ``` c++
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
  ```
</details>

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
  
