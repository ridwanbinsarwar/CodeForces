#include <bits/stdc++.h>
using  namespace std;


/* ALl possible indices between 1 to n */
int n = 4;
void allPossibleIndices() {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {

            if (i & (1 << j)) {
                cout << j << endl;
            }
        }
    }
}
