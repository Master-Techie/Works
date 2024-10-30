#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> words{};
    bool to_continue = true;
    string common = "";

    for (int i = 0; i < 5; i++) {
        string a;
        cin >> a;
        words.push_back(a);
    }

    sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size();});

    for (int i = 0; i < words[0].size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (words[j][i] != words[0][i]) {
                to_continue = false;
                break;
            }
        }

        if (to_continue == false) {break;}
        common += words[0][i];
    }

    cout << common;

    return 0;
}