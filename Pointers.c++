#include <iostream>
using namespace std;

// ? pointers
// int main() {
//     int n  = 5 ;
//     // ! & is the address of operator
//     // ! it gives the address of the variable in memory 
//     cout << "The address if the number stored in n is : " << &n << endl;
    
//     int *ptr = &n; // pointer to n
//     // ! * is the dereference operator
//     // ! it gives the value of the variable at the address stored in the pointer
//     cout << "The value in ptr : " << ptr << endl;
//     cout << "The value of n using pointer is : " << *ptr << endl;
//     cout << "The address of ptr is : " << &ptr << endl;
// }


// ? pointers and arrays
// int main () {
//     int array[10] = {0,9,6,3,1,5,2,7,8,4};
//     cout << "The address of the first element of the array is : " << array << endl;
//     cout << "The address of the first element of the array is : " << &array << endl; 
//     cout << "The address of the first element of the array is : " << &array[0] << endl; // ! this is same as above 2 lines
//     cout << "The address of the first element of the array is : " << &array[0] + 1 << endl; // ! this is increment in the address by 1 
//     cout << "The first element is : " << *array << endl;
//     cout << "The first element + 1 is : " << *array + 1 << endl;
//     cout << "The first element +1 is : " << *(array) + 1 << endl; // ! this is same as above
//     cout << "The second element is : " << *(array + 1) << endl;
//     *array = *array + 2; // ! this is same as array[0] = array[0] + 2;
//     cout << "The first element + 2 is : " << *array << endl;
// }


// ? difference between character array and integer array
// int main () {
//     int arr[10] = {0,9,6,3,1,5,2,7,8,4};
//     char ch[5] = "abcd";
//     cout << arr << endl; // ! this will print the address of the first element of the array
//     cout << ch << endl; // ! this will print the string stored in ch
//     cout << &ch << endl; // ! this will print the address of the first element of ch
//     cout << ch[0] << "  " << ch[2] << "  " << ch[3] << endl; // ! this will print the first, third and fourth element of ch
//     cout << &ch[0] << "  " << &ch[2] << "  " << &ch[3] << endl; // ! this will NOT print address but the character from the given index
//     cout << *ch << "  " << *(ch + 2) << "  " << *(ch + 3) << endl; // ! this will print the first, third and fourth element of ch
// }


// ? pointers and functions
// void update (int *p) {
//     // ! this will update the value of p to 10
//     *p = 10; // ! this will update the value of n to 10
// }
    
// int main () {
//     int n = 5;
//     int *p = &n; 
//     cout << "The value of n before update is : " << n << endl;
//     cout << "The value of p before update is : " << *p << endl;
//     update(p);
//     cout << "The value of n after update is : " << n << endl;
//     cout << "The value of p after update is : " << *p << endl;
// }


// ? Double pointer
int main () {
    int n = 5;
    int *p = &n; // ! pointer to n
    int **q = &p; // ! double pointer to p
    int ***r = &q; // ! triple pointer to q
    cout << "The value of n is : " << n << endl;
    cout << "The value of p is : " << *p << endl;
    cout << "The value of q is : " << **q << endl;
    cout << "The address of n is : " << &n << endl;
    cout << "The address of p is : " << &p << endl;
    cout << "The address of q is : " << &q << endl;
}

