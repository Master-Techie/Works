#include <iostream>
using namespace std;

int main(){
    int s;
    cin >> s;
    int t = s%5;
    int u = s/5;

    if (t == 0) {cout << u;}
    else {cout << u+1;}

    return 0;
}