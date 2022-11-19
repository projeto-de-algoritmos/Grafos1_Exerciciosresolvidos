// https://www.beecrowd.com.br/judge/en/problems/view/2440

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define TAM_MAX 53216

typedef struct _no{

    int u;
    struct _no *prox;

} no;

typedef struct _grafo{

    no **adj;

} grafo_t;

char visitado[TAM_MAX];

grafo_t * inicia_grafo(int);
no * faz_no(int);
void adiciona_no(grafo_t *, int, int);
void dfs(grafo_t *, int);

int main(int argc, char **argv)
{

    int n, m, i, u, v;
    grafo_t *grafo = inicia_grafo(TAM_MAX);
    
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; ++i)
        scanf("%d %d", &u, &v), adiciona_no(grafo, u, v);
    
    int ans = 0;
    for (i = 1; i <= n; ++i)
        if (!visitado[i])
            ++ans, dfs(grafo, i);

    printf("%d\n", ans);

    return 0;

}

grafo_t * inicia_grafo(int _size)
{

    int i;
    grafo_t *grafo = (grafo_t *) malloc(sizeof(grafo_t));
    grafo->adj = (no **) malloc(_size * sizeof(no *));

    for (i = 0; i < _size; ++i)
        grafo->adj[i] = NULL;
 
    return grafo;

}

no * faz_no(int u)
{

    no * novo_no = (no *) malloc(sizeof(no));
    novo_no->u = u;
    novo_no->prox = NULL;

    return novo_no;

}

void adiciona_no(grafo_t *grafo, int u, int v)
{

    no * novo_no = faz_no(v);
    novo_no->prox = grafo->adj[u];
    grafo->adj[u] = novo_no;

    novo_no = faz_no(u);
    novo_no->prox = grafo->adj[v];
    grafo->adj[v] = novo_no;
    
}

void dfs(grafo_t *grafo, int u)
{

    no *i;
    visitado[u] = true;

    for (i = grafo->adj[u]; i != NULL; i = i->prox)
        if (!visitado[i->u])
            dfs(grafo, i->u);

}