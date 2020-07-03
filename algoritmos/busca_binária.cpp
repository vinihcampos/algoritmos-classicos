#include <iostream>

using namespace std;

// Busca binária convencional
int bb(int tamanho_vetor, int v[], int valor){
    int esq = 0; // Índice esquerdo
    int dir = tamanho_vetor - 1; // Índice direito
    int meio; // Índice meio
    while(esq <= dir){ // Condição de parada
        meio = (esq + dir) / 2; // Cálculo do meio
        if(v[meio] == valor) // Verifica se o v na posição meio é igual ao valor procurado
            return meio; // Retorna a posição caso for encontrada
        else if(v[meio] > valor) // Caso v na posição meio seja diferente do valor procurado, verifica-se v nessa posição é maior que o valor.
            dir = meio - 1; // Atualiza o valor do índice dir
        else // Caso contrário
            esq = meio + 1; // Atualiza o valor do índice esq
    }
    return -1; // Condição em que a busca falhou e o elemento não foi encontrado.
}

// Busca binária - caso o valor não esteja na lista, retorna o primeiro elemento que seja maior que o valor
int lowerBB(int tamanho_vetor, int v[], int valor){
    int esq = 0; // Índice esquerdo
    int dir = tamanho_vetor - 1; // Índice direito
    int meio; // Índice meio
    while(dir - esq > 1){ // Condição de parada
        meio = (esq + dir) / 2; // Cálculo do meio
        if(v[meio] == valor) // Verifica se o v na posição meio é igual ao valor procurado
            return meio; // Retorna a posição caso for encontrada
        else if(v[meio] > valor) // Caso v na posição meio seja diferente do valor procurado, verifica-se v nessa posição é maior que o valor.
            dir = meio; // Atualiza o valor do índice dir
        else // Caso contrário
            esq = meio; // Atualiza o valor do índice esq
    }
    if(v[esq] >= valor) return esq; //Caso v[esq] > valor, retorna-se esq
    else if(v[dir] >= valor) return dir; //Caso v[dir] > valor, retorna-se esq
    else return -1; // Caso não exista algum elemento dentro de 'v' que seja maior que valor, retorna-se -1
}

// Busca binária - caso o valor não esteja na lista, retorna o menor elemento que seja mais próximo do valor
int upperBB(int tamanho_vetor, int v[], int valor){
    int esq = 0; // Índice esquerdo
    int dir = tamanho_vetor - 1; // Índice direito
    int meio; // Índice meio
    while(dir - esq > 1){ // Condição de parada
        meio = (esq + dir) / 2; // Cálculo do meio
        if(v[meio] == valor) // Verifica se o v na posição meio é igual ao valor procurado
            return meio; // Retorna a posição caso for encontrada
        else if(v[meio] > valor) // Caso v na posição meio seja diferente do valor procurado, verifica-se v nessa posição é maior que o valor.
            dir = meio; // Atualiza o valor do índice dir
        else // Caso contrário
            esq = meio; // Atualiza o valor do índice esq
    }

    if(v[dir] <= valor) return dir; //Caso v[dir] < valor, retorna-se dir
    else if(v[esq] <= valor) return esq; //Caso v[esq] < valor, retorna-se esq
    else return -1; // Caso não exista algum elemento dentro de 'v' que seja menor que valor, retorna-se -1
}

int main(){

    int v[] = {10,14,19,26,27,31,33,35,42,44};
    int x; cin>>x;
    int resposta = upperBB(sizeof(v)/sizeof(int), v, x);

    if(resposta == -1) cout<<"Não encontrado!"<<endl;
    else cout<<"Valor encontrado na posição "<<resposta<<endl;

    return 0;
}