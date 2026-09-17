#include <iostream>
using namespace std;
int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// nth fibonacci number using recursion
int fibonacci_num(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci_num(n-1) + fibonacci_num(n-2);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    // cout << "Fibonacci Series: ";
    // for(int i = 0; i < n; i++){
    //     cout << fibonacci(i) << " ";
    // }
    // cout << endl;
    cout << "fibonacci_num(" << n << ") = " << fibonacci_num(n) << endl;

    return 0;
}