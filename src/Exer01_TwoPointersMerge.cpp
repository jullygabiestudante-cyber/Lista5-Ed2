#include <bits/stdc++.h>
using namespace std;
int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> vec1(n1), vec2(n2), vec3(n1 + n2);

    for (int i = 0; i < n1; i++) cin >> vec1[i];
    for (int j = 0; j < n2; j++) cin >> vec2[j];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (vec1[i] <= vec2[j]) {
            vec3[k++] = vec1[i++];
        } else {
            vec3[k++] = vec2[j++];
        }
    }
    while (i < n1) vec3[k++] = vec1[i++];
    while (j < n2) vec3[k++] = vec2[j++];

    for (int t = 0; t < n1 + n2; t++) {
        if (t > 0) cout << ' ';
        cout << vec3[t];
    }
    cout << '\n';
}


