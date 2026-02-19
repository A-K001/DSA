#include<iostream>
#include<stack>
using namespace std;

// ? Reversing a string using stack 
int main() {
    string str = "Aayush Kumar";
    stack<char> s;

    for (int i = 0; i < str.length() ; i++){
        s.push(str[i]);
    }

    string ans = "";
    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout << ans << endl;
    return 0;
} 

