#include<stdio.h>
#include<stdlib.h>

struct Graph
{
	int vertices;

	int **table;
	int directed;
	int weighted;
};

struct Graph* initializeGraph(struct Graph* g1, int v, int ch, int ch2)
{	

	struct Graph* temp;
	temp = (struct Graph*)malloc(sizeof(struct Graph*));
	temp->vertices=v;
	temp->table=(int**)malloc(sizeof(struct Graph));
	for(int i=0;i<v;i++)
	{
		temp->table[i]=(int*)malloc(v*sizeof(int));
		for(int j=0;j<v;j++)
		{
			temp->table[i][j]=0;
		}

	}
	temp->directed=ch;
	temp->weighted=ch2;

	return temp;
}

void addEdge(struct Graph* g1, int v1, int v2)
{
	g1->table[v1][v2]=1;
	if(!g1->directed)
		g1->table[v2][v1]=1;

}

void addWeightedEdge(struct Graph* g1, int v1, int v2, int weight)
{
	g1->table[v1][v2]=1*weight;
	if(!g1->directed)
		g1->table[v2][v1]=1*weight;

}

void dispAdjMat(struct Graph* g1)
{
	printf("Adjacency Matrix: \n");
	for(int i=0;i<g1->vertices;i++)
	{
		for(int j=0;j<g1->vertices;j++)
		{
			printf("%d ",g1->table[i][j]);
		}
		printf("\n");
	}
}

void dispAdjList(struct Graph* g1)
{
	printf("Adjacency List: \n");
	for(int i=0;i<g1->vertices;i++)
	{
		for(int j=0;j<g1->vertices;j++)
		{
			if(g1->table[i][j]==1)
			{
				printf("%d -> %d  ",i,j);
			}
			else if ( g1->table[i][j]>1)
			{
				printf("%d -> (%d,%d)  ",i,j,g1->table[i][j]);
			}
		}
		printf("\n");
	}
}



void main()
{

	printf("Select directed/undirected(1/0): ");
	int ch;
	scanf("%d",&ch);

	printf("Select weighted/unweighted(1/0): ");
	int ch2;
	scanf("%d",&ch2);

	int v;
	printf("Enter the number of vertices: ");
	scanf("%d", &v);

	struct Graph* g1;
	g1 = initializeGraph(g1,v,ch,ch2);

	int edg;
	printf("Enter no of edges: ");
	scanf("%d",&edg);

	for(int i=0;i<edg;i++)
	{
		if(!ch2)
		{
			printf("enter edge %d vertices: ", i+1);
			int v1,v2;
			printf("Enter vertices: ");
			scanf("%d %d",&v1,&v2);
			addEdge(g1,v1,v2);
		}
		else
		{
			printf("enter edge %d vertices: ", i+1);
			int v1,v2;
			printf("Enter vertices: ");
			scanf("%d %d",&v1,&v2);
			int weig;
			printf("Enter weight: ");
			scanf("%d",&weig);

			addWeightedEdge(g1,v1,v2,weig);
		}

	}

	
	dispAdjMat(g1);
	dispAdjList(g1);


}