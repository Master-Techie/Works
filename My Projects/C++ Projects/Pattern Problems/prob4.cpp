#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Rows : ";
    cin >> n;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (j<i) {
                cout << " ";
            }

            else {
                cout << "*";
            }

            cout << " ";
        }

        cout << "\n";
    }

    return 0;
}