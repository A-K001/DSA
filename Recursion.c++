# include <iostream>
using namespace std;


// ? Recursion is a process in which a function calls itself directly or indirectly. The function that calls itself is called a recursive function. Recursion is used to solve problems that can be broken down into smaller sub-problems of the same type.
// ? A recursive function has two main components:
// ? 1. Base case: The condition under which the function stops calling itself. This prevents infinite recursion.
// ? 2. Recursive case: The part of the function that calls itself with a modified argument, moving towards the base case.
// ? Recursion is often used in algorithms such as searching, sorting, and traversing data structures like trees and graphs.

// ? Factorial of a number using recursion

// int factorial (int n) {
    
//     if (n == 0 || n == 1) { // ! base case for recursion 
//         return 1 ;
//     }
//     else {
//         return n * factorial(n - 1) ;
//     }
// }
// int main () {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     cout << "The factorial of " << n << " is " << factorial(n) << endl;
//     return 0;
// }


// ? counting the number 
// void countfw (int n) {  // ! head recursion
//     if (n == 0) { // ! base case for recursion 
//         return;
//     }
//     countfw(n - 1); // ! recursive case for recursion 
//     cout << n << " ";
// }
// void countbk (int n) {  // ! tail recursion
//     if (n == 0) { // ! base case for recursion 
//         return;
//     }
//     cout << n << " ";
//     countbk(n - 1); // ! recursive case for recursion 
// }

// int main (){
//     int n;
//     cout << "Enter a number : ";
//     cin >> n;
//     cout << "Counting forward" << endl;
//     countfw(n);
//     cout << endl;
//     cout << "Counting backward" << endl;
//     countbk(n);
// }


// ? Say Digit
// void saydigit (int n , string arr[]) {
//     if (n == 0) {
//         return;
//     }
//     int digit = n % 10 ;
//     saydigit (n /10 , arr);
//     cout << arr[digit] << " ";
// }

// int main (){
//     string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//     int n;
//     cout << "Enter a number : ";
//     cin >> n; 
//     cout << "The number is : ";
//     saydigit ( n , arr );
//     return 0;
// } 


// ? recursion in array

// ? issorted or not
// int issorted (int arr[] , int n){
//     if (n == 0 || n == 1 ){
//         cout << "sorted, ";
//         return 1 ;
//     }
    
//     if (arr[0] > arr[1]) {
//         cout << "not sorted, ";
//         return 0 ;
//     }
//     else {
//         issorted(arr + 1 , n - 1);
//     }
//     return 1;
// }

// int main () {

//     int n;
//     cout << "Enter the size of the array : ";
//     cin >> n;
//     int *arr = new int[n] ;
//     cout << "Enter the elements of the array : ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << "The elements of the array are " << issorted(arr, n) << endl; 
// }


// ? Linear Search using recursion
// void linearSearch ( int arr[] , int n , int key) {
//     if ( n == 0 ) {
//         cout << "Not found " << endl;
//         return ;
//     }
//     if (arr[0] == key ){
//         cout << "Found" << endl;
//         return;
//     }
//     else{
//         linearSearch  (arr + 1 , n-1 , key);
//     }
// }
    
// int main () {
//     int n;
//     cout << "Enter the size of the array : ";
//     cin >> n;
//     int *arr = new int[n] ;
//     cout << "Enter the elements of the array : ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int key;
//     cout << "Enter the element to be searched : ";
//     cin >> key;
//     linearSearch  (arr , n , key);
//     return 0;
// }


// ? Binary Search using recursion
// int binarySearch (int arr[] , int s , int e , int key){
//     if (s > e) {
//         cout << "not found" << endl;
//         return -1;
//     } 
//     int mid = s + (e - s) / 2;
//     if ( arr[mid] == key ){
//         cout << "Found at index : " << mid << endl;
//         return mid;
//     }         
    
//     if (key < arr[mid]) {
//         return binarySearch( arr , s , mid - 1 , key );
//     }
//         return binarySearch (arr , mid + 1 , e , key );
        
// }

// int main (){
//     int n;
//     cout << "Enter the size of the array : ";
//     cin >> n;
//     int *arr = new int [n];
//     cout << "Enter the elements of the array in sorted way : ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int key;
//     cout << "Enter the element to be searched : ";
//     cin >> key;
//     binarySearch (arr , 0 , n - 1 , key );
//     delete [] arr;
//     return 0;
// }


// ? Power of a number using recursion
// double power (int a , int b ) {
//     if (b == 0){ 
//         return 1;
//     }
//     if ( b == 1){
//         return a;
//     }
//     bool isNegative = b < 0 ;
    
//     int exp = abs(b);

//     double ans = power ( a , exp/2 ) ;

//     if (exp & 1){
//         ans = a * (ans * ans) ;
//     }
//     else {
//         ans =  ans * ans;
//     }
    
//     return isNegative ? 1.0 / ans : ans ; 
// }

// int main (){
//     int a,b;
//     cout << "Enter a number and its power : " ;
//     cin >> a;
//     cin >> b;
//     cout << a << " To the power "<< b << " is : " << power(a , b) << endl;
//     return 0;
// }









        