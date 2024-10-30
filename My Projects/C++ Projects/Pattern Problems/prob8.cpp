#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Rows : ";
    cin >> n;
    int s = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i+j+s << " ";

            s += (n-2)-j;
        }

        s = 1;
        cout << "\n";
    }

    return 0;
}