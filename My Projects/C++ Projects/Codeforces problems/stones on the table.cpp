#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    cin >> s;
    int total = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {total++;}
    }

    cout << total;

    return 0;
}