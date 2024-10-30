#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = s.size();

    for (int i = 0; i < e; i++) {
        if (s[i] == '1') {a++;}
        else if (s[i] == '2') {b++;}
        else if (s[i] == '3') {c++;}
        else {d++;}
    }

    for (int i = 0; i < a; i++) {
        cout << "1";

        if (d > 0) {
            cout << "+";
            d--;
        }
    }

    for (int i = 0; i < b; i++) {
        cout << "2";

        if (d > 0) {
            cout << "+";
            d--;
        }
    }

    for (int i = 0; i < c; i++) {
        cout << "3";

        if (d > 0) {
            cout << "+";
            d--;
        }
    }

    return 0;
}