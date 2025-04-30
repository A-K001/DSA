#include <iostream>
using namespace std;

// ? Code to find prime numbers using sieve of Eratosthenes 
// this solves the problem of TLE because the older versions time complexity was O(n^2) and this is O(nlog(logn))
// this is a very efficient algorithm to find prime numbers in a range of numbers

// bool isPrime (int n){
//     if (n <= 1)
//         return false;
    
//     for (int i = 2 ; i < n ; i++){
//         if (n%i == 0)
//             return false;
//     }
//     return true;
// }

// int countPrime (int n){
//     int count = 0;
//     int prime[n+1];
//     for (int i = 0 ; i < n+1 ; i++){
//         prime[i] = true;
//     }
//     prime[0] = prime[1] = false;

//     for (int i = 2 ; i < n ; i++ ){
//         if (prime[i]){
//             count++;

//             for (int j = 2*i ; j < n ; j = j + i){
//                 prime[j] = false;
//             }
//         }
//     }
//     return count;
// }
// int main (){
//     int n;
//     cout << "Enter the number till which u want to find no. of prime numbers: ";
//     cin >> n;
//     cout << endl;
//     cout << "----------------------------------------" << endl;
//     cout << "using brute force i.e isPrime Function" << endl;
    
//     int count = 0;
//     // this is a brute force method to find prime numbers in a range of numbers
//     for(int i  = 2 ; i < n ; i++){    
//         if (isPrime(i)){
//             count++;
//         }
//     }
//     cout << "The number of prime numbers till " << n << " is: " << count << endl;
//     cout << endl; 
//     cout << "----------------------------------------" << endl;
//     cout << "using sieve of Eratosthenes" << endl;
//     cout << "The number of prime numbers till " << n << " is: " << countPrime(n) << endl;
//     cout << endl;
//     return 0;    
// }


int gcd (int a , int b){
    if (b == 0){
        return b;
    }
    if  (a == 0 ){
        return a;
    }
    
    while (a != b ){
        if (a > b){
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int main () {
    int a , b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a , b) << endl;
    return 0;
    
}