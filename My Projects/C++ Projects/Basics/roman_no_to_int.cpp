#include <iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter any roman no. between I and MMMCMXCIX : ";
    cin >> s;
    int n = s.length();
    int i = 0;
    int numeral = 0;

    while (i < n) {
        if (s[i] == 'M') {
            numeral += 1000;
            }
            
        else if (s[i] == 'D') {
            numeral += 500;
            }

        else if (s[i] == 'C') {
            if (s[i+1] == 'M' || s[i+1] == 'D') {
                numeral -= 100;
            }

            else {
                numeral += 100;
            }
            }

        else if (s[i] == 'L') {
            numeral += 50;
            }

        else if (s[i] == 'X') {
            if (s[i+1] == 'C' || s[i+1] == 'L') {
                numeral -= 10;
            }

            else {
                numeral += 10;
            }
            }

        else if (s[i] == 'V') {
            numeral += 5;
            }

        else if (s[i] == 'I') {
            if (s[i+1] == 'X' || s[i+1] == 'V') {
                numeral -= 1;
            }

            else {
                numeral += 1;
            }
            }

        i++;
    }

    cout << numeral;

    return 0;
}