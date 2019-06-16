#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_fun(string s) {
    int n = (int)s.size();
    vector<int>pi(n);
    for (int i = 1; i<n; ++i) {
        int j = pi[i-1];
        while (j>0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string txt;
    string pat;
    cin >> txt;
    cin >> pat;

    int i, j;
    i = j = 0;

    auto lps = prefix_fun(pat);

    while(i < txt.size()) {
        if(pat[j] == txt[i]){
            i++;
            j++;
        }

        if(j == pat.size()) {
            cout << "found at" << " " << i - j << endl;
            j = lps[j-1];
        }
        else if(i < txt.size() && pat[j] != txt[i]) {

            if(j!=0)
                j = lps[j-1];
            else
                i+=1;
        }
    }
}