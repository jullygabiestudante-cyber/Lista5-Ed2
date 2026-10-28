#include <bits/stdc++.h>
using namespace std;

struct jogador {
    string nome;
    int pontuacao;
};

bool vemAntes(const jogador& A, const jogador& B) {

    // Caso 1: A tem mais pontos que B → A vem antes
    if (A.pontuacao > B.pontuacao) {
        return true;
    }

    // Caso 2: A tem menos pontos que B → A NÃO vem antes
    if (A.pontuacao < B.pontuacao) {
        return false;
    }

    // Caso 3: empate nos pontos → desempata pelo nome
    // (nome que vem primeiro no alfabeto fica antes)
    if (A.nome < B.nome) {
        return true;
    } else {
        return false;
    }
}
int particao(vector<jogador>& vec, int inicio, int fim) {
    jogador pivo = vec[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vemAntes(vec[j], pivo)) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[fim]);
    return i + 1;

}

void quickSort(vector<jogador>& vec, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particao(vec, inicio, fim);
        quickSort(vec, inicio, pivo - 1);
        quickSort(vec, pivo + 1, fim);
    }
}

int main() {
    int n;
    cin >> n;
    vector<jogador> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i].nome >> vec[i].pontuacao;

    quickSort(vec, 0, n - 1);

    for (int i = 0; i < n; i++) {

        cout << vec[i].nome << ' ' << vec[i].pontuacao << '\n';
    }
}