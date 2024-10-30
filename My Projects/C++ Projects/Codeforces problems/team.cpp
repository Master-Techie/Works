#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int scores = 0;

    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;

        if (a+b+c > 1) {
            scores++;
        }
    }

    cout << scores;

    return 0;
}