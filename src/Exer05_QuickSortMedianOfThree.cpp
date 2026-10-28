#include <bits/stdc++.h>
using namespace std;

// Coloca a mediana de (início, meio, fim) na última posição e devolve o valor dela
int medianaDeTres(vector<int>& vec, int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    // ordena os três valores entre si
    if (vec[meio] < vec[inicio]) swap(vec[meio], vec[inicio]);
    if (vec[fim]  < vec[inicio]) swap(vec[fim],  vec[inicio]);
    if (vec[fim]  < vec[meio])   swap(vec[fim],  vec[meio]);

    // agora vec[meio] é a mediana: leva ela para o fim, onde o Lomuto espera o pivô
    swap(vec[meio], vec[fim]);
    return vec[fim];
}

int particao(vector<int>& vec, int inicio, int fim) {
    int pivo = vec[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vec[j] < pivo) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[fim]);
    return i + 1;
}

void quickSort(vector<int>& vec, int inicio, int fim, bool raiz) {
    if (inicio < fim) {
        int pivo = medianaDeTres(vec, inicio, fim);

        if (raiz) {
            cout << "Pivo inicial: " << pivo << '\n';
        }

        int p = particao(vec, inicio, fim);
        quickSort(vec, inicio, p - 1, false);
        quickSort(vec, p + 1, fim, false);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    quickSort(vec, 0, n - 1, true);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << vec[i];
    }
    cout << '\n';
}