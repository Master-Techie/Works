#include <iostream>
using namespace std;

int main(){
    string a,b;
    cin >> a;
    cin >> b;
    int k = a.size();
    int flag = 0;

    for (int i = 0; i < k; i++) {
        if (a[i] > 90) {a[i] -= 32;}
        if (b[i] > 90) {b[i] -= 32;}

        if (a[i] > b[i]) {
            flag++;
            break;
        }

        else if (a[i] < b[i]) {
            flag--;
            break;
        }
    }

    cout << flag;

    return 0;
}