#include <bits/stdc++.h>
using namespace std;

int fib_iterative(int n) {
    int count = 0;
    int first = 0, second = 1, next = 0;

    cout << "Fibonacci Series: ";
    cout << first << " " << second << " ";

    for(int i = 0; n-1>i; i++){
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
        count++;
    }
    cout<<endl;

    cout << "-------------"<<endl;
    cout<<"Iterative digit: "<<next<<endl;

    return count+1;
}

pair<long long, int> fib_recursive(int n) {
    if (n < 0)
        return make_pair(-1, 1);
    if (n == 0 || n == 1)
        return make_pair(n, 1);
        
    pair<long long, int> fib1 = fib_recursive(n - 1);
    pair<long long, int> fib2 = fib_recursive(n - 2);
    
    return make_pair(fib1.first + fib2.first, fib1.second + fib2.second + 1);
}

int main() {
    int n, count = 2;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Count: " << fib_iterative(n) << endl;
    cout<<"------------"<<endl;
    cout << "Recursive: " << fib_recursive(n).first << endl;
    cout << "Steps: " << fib_recursive(n).second << endl;

    return 0;
}