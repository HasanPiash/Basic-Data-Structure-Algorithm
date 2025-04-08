#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string S, X;
        cin >> S >> X;

        int a = X.size();
        int b = S.size();

        for (int j = 0; j <= b -a; j++) {
            bool found = true;
            for (int k = 0; k < a; k++) {
                if (S[j + k] != X[k]) {
                    found = false;
    
                }
            }

            if (found) {
                S.replace(j, a, "#");
                b = S.size();
            }
        }

        cout << S << endl;
    }

    return 0;
}
