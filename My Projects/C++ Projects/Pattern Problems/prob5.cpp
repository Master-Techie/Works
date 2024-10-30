#include <iostream>
using namespace std;

void blanks(int n){
    while (n--) {
        cout << "  ";
    }
}

void stars(int n){
    while (n--) {
        cout << "*" << " ";
    }
}

int main(){
    int n;
    cout << "Rows : ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        blanks(n-i);
        stars((i*2) - 1);
        blanks(n-i);

        cout << "\n"; 
    }

    return 0;
}