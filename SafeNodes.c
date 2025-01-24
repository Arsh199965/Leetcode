#include<stdio.h>
#include<stdlib.h>
int *eventualSafeNodes(int **graph, int graphSize, int *graphColSize, int returnSize)
{
    int ans[returnSize];
    int visited[graphSize];
    int k=0;
    for (int i = 0; i < graphSize; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < graphSize; i++)
    {
        if (!dfs(graph, i, visited, graphColSize))
        {
            printf("%d ", i);
            
            k++;
        }
    }
}
int dfs(int **graph, int row, int visited[], int colSize[])
{
    if (visited[row] == 1)
    {
        return 1;
    }
    if (visited[row] == 2)
    {
        return 0;
    }
    if (colSize[row] == 0)
    {
        visited[row] = 2;
        return 0;
    }

    visited[row] = 1;
    for (int i = 0; i < colSize[row]; i++)
    {
        if (dfs(graph, graph[row][i], visited, colSize))
        {
            return 1;
        }
    }
    visited[row] = 2;
    return 0;
}






void printGraph(int **graph, int row, int col[])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    int row = 5, col = 4;

    int **graph;
    int colSize[7] = {0, 4, 1, 1, 0};
    graph = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        graph[i] = (int *)malloc(colSize[i] * sizeof(int)); 
    }

    int initGraph[7][2] = { {}, { 0, 2, 3, 4 }, {3}, {4}, {} };
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colSize[i]; j++)
        {
            graph[i][j] = initGraph[i][j];
        }
    }
    eventualSafeNodes(graph, row, colSize, 4);

    return 0;
    
}