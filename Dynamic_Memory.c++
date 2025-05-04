#include <iostream>
using namespace std;


// ? dynamic memory allocation in normal variable
// int main() {
//     int i = 5;
//     int &j = i; // ! reference variable
//     int *p = new int; // ! dynamic memory allocation
//     *p = 10; // ! assigning value to the dynamically allocated memory
//     cout << "i: " << i << endl;
//     cout << "j: " << j << endl;
//     cout << "p: " << *p << endl;
//     cout << "Address of i: " << &i << endl;
//     cout << "Address of j: " << &j << endl;
//     cout << "Address stored in p: " << p << endl;
//     cout << "Address of *p: " << &(*p) << endl;
//     cout << "Address of p: " << &(p) << endl;
//     delete p; // ! deallocating memory
//     return 0;
// }


// ? dynamic memory allocation in arrays
// int getSum (int *arr , int n){
//     int sum = 0;
//     for (int i = 0 ; i < n ; i++ ){
//         sum += arr[i];
//     }
//     return sum;
// }

// int main () {
//     int n;
//     cout << "Enter the size of the aray : " ;
//     cin >> n;
//     cout << endl;
//     int *arr = new int[n]; // ! dynamic memory allocation for array (good practice)
//     for (int i = 0 ; i < n ; i++) {
//         cout << "Enter the element " << i + 1 << " : ";
//         cin >> arr[i];
//     }
//     cout << endl;
//     cout << "The sum of the array is : " << getSum(arr , n) << endl;
//     delete [] arr; // ! deallocating memory
//     cout << "Memory deallocated successfully" << endl;
//     return 0;
// }


// ? dynamic memory allocation in 2D arrays
int main() {
    int r,c;
    cout << "Enter the number of rows and columns : ";
    cin >> r >> c;
    cout << endl;
    int **arr = new int *[r]; // ! dynamic memory allocation for rows at once
    //! int arr[r][c]; static memory allocation for 2D array (not good practice)
    for (int i = 0 ; i < r ; i++) {  
    // ! dynamic memory allocation for columns one by one
        arr[i] = new int [c]; //! *( arr + i ) = new int [c]; can also be written like this 
    }
    
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cout << "Enter the element at " << i + 1 << " row and " << j + 1 << " column : ";
            cin >> arr[i][j]; // ! arr[i][j] = *(arr[i] + j); can also be written like this 
        }
    }
    cout << endl;
    cout << "The 2D array is : " << endl;
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0 ; i < r ; i++){
        delete [] arr[i] ; // ! deallocating memory for columns one by one
    }
    delete [] arr; // ! deallocating memory for rows at once
    cout << "Memory deallocated successfully" << endl;
    return 0;
}







