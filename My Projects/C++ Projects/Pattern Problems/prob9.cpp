#include <iostream>
using namespace std;

/*
Pattern : 

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

and so on ...
*/

int main(){
    int n;
    cout << "Rows : ";
    cin >> n;

    for (int i = 0; i < n; i++){
        int s = 1;
        for (int j = 0; j <= i; j++) {
            if ((j == 0) || (i == j)) {
                cout << 1;
            }

            else {
                s *= (i-j+1);
                s /= j;
                cout << s;
            }

            cout << " ";
        }

        cout << "\n";
    }

    return 0;
}