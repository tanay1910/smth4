#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int vertices;

    int **table;
};

void addEdge(struct Graph *g1, int v1, int v2)
{
    g1->table[v1][v2]=1;
}

void printAdjMatrix(struct Graph* g1)
{
    for(int i=0;i<g1->vertices;i++)
    {
        for(int j=0;j<g1->vertices;j++)
        {
            printf("%d ", g1->table[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    struct Graph *g1;
    g1 = (struct Graph*)malloc(sizeof(struct Graph));
    
    int v;
    printf("Enter no of vertices: ");
    scanf("%d",&v);

    g1->vertices=v;

    g1->table=(int **)malloc(sizeof(int *));
    for(int i=0;i<v;i++)
    {
        g1->table[i]=(int*)malloc(sizeof(int));
        for(int j=0;j<v;j++)
        {
            g1->table[i][j]=0;
        }
    }

    

    addEdge(g1,0,1);

    printAdjMatrix(g1);


}