#include <iostream>
#include <vector>
using namespace std;

/*
I -> 1, II -> 2, III -> 3, IV -> 4
V -> 5, IX -> 9
X -> 10, XX -> 20, XXX -> 30, XL -> 40
L -> 50, XC -> 90
C -> 100, CC -> 200, CCC -> 300, CD -> 400
D -> 500, CM -> 900
M -> 1000, MM -> 2000, MMM -> 3000
*/

string multi_str_add(string r, string x, int n){
    for (int i = 0; i < n; i++) {
        r += x;
    }

    return r;
}

string i_to_r(int i){
    string r = "";
    int n;

    vector<int> nums{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> alphas{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for (int j = 0; j < nums.size(); j++) {
        n = i / nums[j];
        r = multi_str_add(r,alphas[j], n);
        i %= nums[j];
    }
    
    // n = i / 1000;
    // r = multi_str_add(r,"M",n);
    // i %= 1000;

    // n = i / 900;
    // r = multi_str_add(r,"CM",n);
    // i %= 900;

    // n = i / 500;
    // r = multi_str_add(r,"D",n);
    // i %= 500;

    // n = i / 400;
    // r = multi_str_add(r,"CD",n);
    // i %= 400;

    // n = i / 100;
    // r = multi_str_add(r,"C",n);
    // i %= 100;

    // n = i / 90;
    // r = multi_str_add(r,"XC",n);
    // i %= 90;

    // n = i / 50;
    // r = multi_str_add(r,"L",n);
    // i %= 50;

    // n = i / 40;
    // r = multi_str_add(r,"XL",n);
    // i %= 40;

    // n = i / 10;
    // r = multi_str_add(r,"X",n);
    // i %= 10;

    // n = i / 9;
    // r = multi_str_add(r,"IX",n);
    // i %= 9;

    // n = i / 5;
    // r = multi_str_add(r,"V",n);
    // i %= 5;

    // n = i / 4;
    // r = multi_str_add(r,"IV",n);
    // i %= 4;

    // r = multi_str_add(r,"I",i);

    return r;
}

int main(){
    int n = 777;
    string r = i_to_r(n);
    cout << r;

    return 0;
}