#include <iostream>
using namespace std;

string is_palindrome(int x) {
    int m = 0;
    int n = x;

    if (x < 0) {
        return "false";
    }

    while (n > 0) {
        int r = n%10;
        m *= 10;
        m += r;
        n /= 10;
    }

    if (m == x) {
        return "true";
    }

    else {
        return "false";
    }
}

int main(){
    int x;
    cout << "Enter the number : ";
    cin >> x;

    string c = is_palindrome(x);
    cout << c;

    return 0;
}