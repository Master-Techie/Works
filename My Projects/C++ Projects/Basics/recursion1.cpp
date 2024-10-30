#include <iostream>
using namespace std;

void pr(int n, int r = 1) {
    if (r == n) {
        cout << n;
        return;
    }

    cout << r;
    pr(n, r+1);
    
}

int main(){
    int t = 5;
    pr(15);

    return 0;
}