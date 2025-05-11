#include <iostream>
#include <vector>
using namespace std;

// ? Merge Sort by using indexing
// void print (vector <int> &arr , int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void merge (vector <int> &arr , int s , int e , int mid) {
//     int i = s , j = mid + 1;
//     vector <int > temp;
    
//     // ! merging the two sorted arrays in a sorted way
//     // ! first array is from s to mid and second array is from mid + 1 to e
//     while ( i <= mid && j <= e ){
//         if (arr [i] < arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }
//        else{
//             temp.push_back(arr[j]);
//             j++;
//        }
//     }
//     while (i <= mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
//     while (j <= e) { 
//         temp.push_back(arr[j]);
//         j++;
//     }

//     // ! copying the temp array to the original array
//     for (int i = 0 ; i < temp.size() ; i++) {
//         arr[i+s] = temp[i];
//     }
//     return ;
// }
// void mergeSort (vector <int> &arr , int s , int e){
    
//     if (s < e ) {
        
//         int mid = s + (e - s) / 2 ;
        
//         mergeSort(arr , s , mid); // ! passing left
//         mergeSort(arr , mid +1 , e); // ! passing right
        
//         merge(arr , s , e , mid);
//     }
//     return;
// }

// int main (){
//     int n;
//     vector <int> arr;
//     cout << "Enter the size of the array : " ;
//     cin >> n;
//     cout << "Enter the elements of the array : " ;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         arr.push_back(x);
//     }
//     cout << endl;
//     cout << "The elements of the array are : " ;
//     print(arr , n);
//     cout << endl;
//     mergeSort (arr , 0 , n - 1 );
//     cout << "The sorted array is : " ;
//     print (arr , n);
//     cout << endl;
//     return 0;
// }

/* 
Recursive tree for the example [1, 1, 3, 4]

mergeSort(0, 3)      // depth 0
├── mergeSort(0, 1)  // depth 1
│   ├── mergeSort(0, 0)  // depth 2 → base case
│   └── mergeSort(1, 1)  // depth 2 → base case
│   └── merge(0, 1)      → [1, 3]
├── mergeSort(2, 3)  // depth 1
│   ├── mergeSort(2, 2)  // depth 2 → base case
│   └── mergeSort(3, 3)  // depth 2 → base case
│   └── merge(2, 3)      → [1, 4]
└── merge(0, 3)          → [1, 1, 3, 4]
*/

// ? Merge Sort by creating a new array & copying the values to it
// void merge(int *arr, int s, int e) {

//     int mid = (s+e)/2;

//     int len1 = mid - s + 1;
//     int len2 = e - mid;

//     int *first = new int[len1];
//     int *second = new int[len2];

//     //copy values
//     int mainArrayIndex = s;
//     for(int i=0; i<len1; i++) {
//         first[i] = arr[mainArrayIndex++];
//     }

//     mainArrayIndex = mid+1;
//     for(int i=0; i<len2; i++) {
//         second[i] = arr[mainArrayIndex++];
//     }

//     //merge 2 sorted arrays     
//     int index1 = 0;
//     int index2 = 0;
//     mainArrayIndex = s;

//     while(index1 < len1 && index2 < len2) {
//         if(first[index1] < second[index2]) {
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else{
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }   

//     while(index1 < len1) {
//         arr[mainArrayIndex++] = first[index1++];
//     }

//     while(index2 < len2 ) {
//         arr[mainArrayIndex++] = second[index2++];
//     }

//     delete []first;
//     delete []second;

// }

// void mergeSort(int *arr, int s, int e) {

//     //base case
//     if(s >= e) {
//         return;
//     }
    
//     int mid = (s+e)/2;

//     //left part sort karna h 
//     mergeSort(arr, s, mid);
    
//     //right part sort karna h 
//     mergeSort(arr, mid+1, e);

//     //merge
//     merge(arr, s, e);

// }

// int main() {

//     int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
//     int n = 15;

//     mergeSort(arr, 0, n-1);

//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     } cout << endl;

//     return 0;
// }


// ? Quick Sort
int partition (int arr [] , int s , int e ) {
    int idx = s;
    int pivot = arr[s];
    for (int j = s + 1 ; j <= e ; j++ ) {
        cout << "j = " << j << endl;
        if (arr[j] <= pivot) {
            idx ++;
            cout << "idx = " << idx << endl;
            swap(arr[idx] , arr[j]);
            for (int i = s; i < e+1; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    cout << "pivot = " << pivot << endl;
    cout << "idx out side = " << idx << endl;
    cout << "s = " << s << endl;
    cout << "e = " << e << endl;
    cout << endl;
    swap(arr[s] , arr[idx]);
    return idx;
}

void quickSort (int arr [] , int s , int e) {
    if (s >= e) {
        return ;
    }
    int pidx = partition(arr , s , e);
    quickSort(arr , s , pidx - 1);
    quickSort(arr , pidx + 1 , e);
    return ;
} 

void print (int arr [] , int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main (){
    int n;
    cout << "Enter the size of the array : " ;
    cin >> n;
    int *arr = new int[n] ;
    cout << "Enter the elements of the array : " ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "The elements of the array are : " ;
    print(arr , n);
    cout << endl;
    quickSort(arr , 0 , n - 1 );
    cout << "The sorted array is : " ;
    print (arr , n);
    cout << endl;
    delete [] arr;
    return 0;
}

/*
Recursive tree for the example [5, 3, 8, 4, 2] 
quickSort(0, 4)
├── quickSort(0, 2)
│   ├── quickSort(0, -1) → base
│   └── quickSort(1, 2)
│       ├── quickSort(1, 0) → base
│       └── quickSort(2, 2) → base
└── quickSort(4, 4) → base
*/