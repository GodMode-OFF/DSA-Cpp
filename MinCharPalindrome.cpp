#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter your string: ";
    cin >> str;
    
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    string concat = str + '$' + rev;
    int n = concat.size();
    
    vector<int> lps(n, 0);
    int pre = 0, suf = 1;
    
    while (suf < n) {
        if (concat[pre] == concat[suf]) {
            pre++;
            lps[suf] = pre;
            suf++;
        } else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }
    
    int size = str.size();
    int charsToAdd = size - lps[n - 1];
    
    cout << "The answer for palindrome with min characters is: " << charsToAdd << endl;
    
    return 0;
}
