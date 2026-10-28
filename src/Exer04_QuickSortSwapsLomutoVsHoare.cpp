#include <bits/stdc++.h>
using namespace std;

int particao(vector<int>& vec, int inicio, int fim, int& trocas) {
    int i = inicio - 1;
    int pivo = vec[fim];

    for (int j = inicio; j < fim; j++) {
        if (vec[j] <= pivo) {
            i++;
            if (i != j) {
                swap(vec[i], vec[j]);
                trocas++;
            }
        }
    }
    if (i + 1 != fim) {
        swap(vec[i + 1], vec[fim]);
        trocas++;
    }
    return i + 1;
}

void quickLomuto(vector<int>& vec, int inicio, int fim, int& trocas) {
    if (inicio < fim) {
        int pi = particao(vec, inicio, fim, trocas);
        quickLomuto(vec, inicio, pi - 1, trocas);
        quickLomuto(vec, pi + 1, fim, trocas);
    }
}
int particaoHoare(vector<int>& v, int inicio, int fim, int & trocas) {
    int pivo = v[inicio];
    int i = inicio - 1;
    int j = fim + 1;

    while (true) {
        do {
            i++;
        } while (v[i] < pivo);  // i procura um elemento >= pivô

        do {
            j--;
        } while (v[j] > pivo);   // j procura um elemento <= pivô

        if (i >= j) return j;            // cruzaram: fim da partição

        swap(v[i], v[j]);       // aqui i < j sempre, então é troca efetiva
        trocas++;
    }
}

void quickHoare(vector<int>& v, int inicio, int fim, int & trocas) {
    if (inicio < fim) {
        int p = particaoHoare(v, inicio, fim, trocas);
        quickHoare(v, inicio, p, trocas);
        quickHoare(v, p + 1, fim, trocas);
    }
}

void imprimir(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) cout << ' ';
        cout << vec[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<int> vLomuto = original;
    vector<int> vHoare  = original;

    int trocasLomuto = 0;
    int trocasHoare = 0;

    quickLomuto(vLomuto, 0, n - 1, trocasLomuto);
    quickHoare(vHoare, 0, n - 1, trocasHoare);

    cout << "Lomuto: " << trocasLomuto << " trocas\n";
    cout << "Hoare: "  << trocasHoare  << " trocas\n";

    if (trocasLomuto < trocasHoare) {
        cout << "Menos trocas: Lomuto\n";
        imprimir(vLomuto);
    } else if (trocasHoare < trocasLomuto) {
        cout << "Menos trocas: Hoare\n";
        imprimir(vHoare);
    } else {
        cout << "Menos trocas: Empate\n";
        imprimir(vHoare);
    }
}


