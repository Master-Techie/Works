#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int n) {
    bool prime = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) {
            prime = false;
        }
    }

    return prime;
}

int main(){
    int x[10];
    int c = 0;
    
    for (int i = 2; i < 30; i++) {
        if (c == 10) {
            break;
        }

        bool prime_or_not = isprime(i);

        if (prime_or_not == true) {
            x[c] = i;
            c++;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            cout << x[j] << " ";
        }

        cout << "\n";
    }

    return 0;

}