#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        if (n > 10) {
            cout << s[0] << n-2 << s[n-1] << "\n";
        }

        else {cout << s << "\n";}
    }

    return 0;
}