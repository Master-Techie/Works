#include <iostream>
using namespace std;

int main(){
    string haystack;
    string needle;
    cin >> haystack >> needle;
    
    int a = haystack.size();
    int b = needle.size();
    
    int pos = -1;
    
    for (int i = 0; i < a-b; i++) {
        if (haystack.substr(i, b) == needle) {
            pos = i;
            break;
        }
    }
    
    cout << pos;
    
    return 0;
}