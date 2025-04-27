#include <iostream>
using namespace std;

// int main() {
//     // 2D array declaration
//     int arr[3][4] = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12}
//     };

//     // Accessing elements of the 2D array
//     cout << "Element at (0,0): " << arr[0][0] << endl; // Output: 1
//     cout << "Element at (2,3): " << arr[2][3] << endl; // Output: 12

//     // Modifying an element in the 2D array
//     arr[2][3] = 20;
//     cout << "Modified element at (2,3): " << arr[2][3] << endl; // Output: 20

//     return 0;
// }


// int main() {

//     int arr[3][3];
//     cout << "Enter the elements of the 2D array (3x3):" << endl;
//     for (int i = 0; i < 3 ; i++){
//         for (int j = 0 ; j <3 ; j++){
//             cin >> arr[i][j];
//         }
//     } 
//     cout << "The 2D array is:" << endl;
//     for (int i = 0; i < 3 ; i++){
//         for (int j = 0 ; j <3 ; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "The transpose of the 2D array is:" << endl;
//     for (int i = 0; i < 3 ; i++){
//         for (int j = 0 ; j <3 ; j++){
//             cout << arr[j][i] << " ";
//         }
//         cout << endl;
//     }
// }

void PrintRowSum(int arr[][3], int row , int col){
    for (int i = 0 ; i < 3 ; i++){
        int sum = 0 ;
        for (int j = 0 ; j <3 ; j++ ){
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << " is : " << sum << endl;
    }
}
void PrintColSum(int arr[][3], int row , int col){
    for (int i = 0 ; i < 3 ; i++){
        int sum = 0 ;
        for (int j = 0 ; j <3 ; j++ ){
            sum += arr[j][i];
        }
        cout << "Sum of Column " << i << " is : " << sum << endl;
    }
}

int main() {

    int arr[3][3];
    cout << "Enter the elements of the 2D array (3x3):" << endl;
    for (int i = 0; i < 3 ; i++){
        for (int j = 0 ; j <3 ; j++){
            cin >> arr[i][j];
        }
    } 
    cout << "The 2D array is:" << endl;
    for (int i = 0; i < 3 ; i++){
        for (int j = 0 ; j <3 ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    PrintRowSum(arr,3,3);
    PrintColSum(arr,3,3);
    return 0;
}