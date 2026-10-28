
#include<bits/stdc++.h>
using namespace std;


   void merge(vector<int>&  arr, int inicio, int meio, int fim) {
    int n1  =  meio - inicio +1 ;
     int n2 = fim - meio;

    vector<int> esquerda(n1), direita (n2);

    for (int i = 0; i < n1; i++)
      esquerda[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
      direita[j] = arr[meio + j + 1];

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
      if (esquerda[i] <= direita[j]) {
        arr[k++] = esquerda[i++];
      } else {
        arr[k++] = direita[j++];
      }
    }
    while (i < n1) arr[k++] = esquerda[i++];
    while (j < n2) arr[k++] = direita[j++];

     cout << "[Merge " << inicio << ".." << fim << "]:";
     for (int t = inicio; t <= fim; t++) cout << ' ' << arr[t];
     cout << '\n';

}


 void mergesort(vector<int>& arr, int inicio, int fim) {
     if (inicio < fim) {
       int meio = inicio + (fim - inicio) / 2;

       mergesort(arr, inicio, meio);
       mergesort(arr, meio + 1, fim);
       merge(arr, inicio, meio, fim);
     }
   }

     int main() {
      int n;
      cin >> n;
      vector<int> arr(n);
      for (int i = 0; i < n; i++) cin >> arr[i];

      mergesort(arr, 0, n - 1);

      cout << "[Final]:";
      for (int i = 0; i < n; i++) cout << ' ' << arr[i];
      cout << '\n';
    }

