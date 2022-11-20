// https://www.beecrowd.com.br/judge/en/problems/view/1081

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define TAM_MAX 20
#define le_uma_variavel(a) scanf("%d", &a);
#define le_duas_variaveis(a, b) scanf("%d%d", &a, &b);


bool visitado[TAM_MAX];

int grafo[TAM_MAX][TAM_MAX];


void clean(int vertice) {

    int i, j;

    for (i = 0; i < vertice; i++) {
        for (j = 0; j < vertice; j++)
            grafo[i][j] = 0;
        visitado[i] = false;
    }

}

 

bool dfs(int vertice, int num_nos, int num_espacos) {

    int i;
    bool possui_caminho = false;
    visitado[vertice] = true;

    for (i = 0; i < num_nos; i++) {
        if (grafo[vertice][i] == 1) {
            possui_caminho = true;
            if (!visitado[i]) {
                cout << string(num_espacos, ' ');
                printf("%d-%d pathR(G,%d)\n", vertice, i, i);
                dfs(i, num_nos, num_espacos + 2);
            } else {
                cout << string(num_espacos, ' ');
                printf("%d-%d\n", vertice, i);
            }

        }
    }

    return possui_caminho;

}

 

void percorre_dfs(int vertice) {

    int i, index = 0;

    while (1) {

        if (dfs(index, vertice, 2))
            puts("");

        index = -1;

        for (i = 0; i < vertice; i++) {
            if (!visitado[i]) {
                index = i;
                break;
            }
        }

        if (index == -1)
            break;

    }

}

int main(int argc, char const *argv[]) {

    int num_casos, vertice, aresta, noA, noB, caso = 1;

    le_uma_variavel(num_casos);

    while(num_casos--) {

        le_duas_variaveis(vertice, aresta);
        clean(vertice);

        while(aresta--) {
            le_duas_variaveis(noA, noB);
            grafo[noA][noB] = 1;
        }

        printf("Caso %d:\n", caso++);
        percorre_dfs(vertice);

    }

    return 0;

}