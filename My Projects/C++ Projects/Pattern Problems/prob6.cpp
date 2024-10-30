#include <iostream>
using namespace std;

/* 

Pattern :

    *    
  *   *  
*       *
  *   *  
    *    
*/

int main(){
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i%2 == 1) {
                if ((i-j == 2) || (j-i == 2)) {
                    cout << "*";
                }

                else {
                    cout << " ";
                }
            }

            if (i%2 == 0) {
                if ((i == j) || (i-j == 2) || (j-i == 2)) {
                    cout << "*";
                }

                else {
                    cout << " ";
                }
            }

            cout << " ";
        }

        cout << "\n";
    }

    return 0;
}