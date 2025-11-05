#include <stdio.h>
#define INF 999
#define MAX 100

int costMatrix[MAX][MAX], pathMatrix[MAX][MAX];
int numNodes, source, destination;

void floydWarshall()
{
    for (int k = 1; k <= numNodes; k++)
    {
        for (int i = 1; i <= numNodes; i++)
        {
            for (int j = 1; j <= numNodes; j++)
            {
                if (costMatrix[i][k] != INF && costMatrix[k][j] != INF && costMatrix[i][j] > costMatrix[i][k] + costMatrix[k][j])
                {
                    costMatrix[i][j] = costMatrix[i][k] + costMatrix[k][j];
                    pathMatrix[i][j] = pathMatrix[k][j];  
                }
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX])
{
    for (int i = 1; i <= numNodes; i++)
    {
        for (int j = 1; j <= numNodes; j++)
        {
            if (matrix[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void calculatePath(int i, int j)
{
    if (costMatrix[i][j] == INF)
    {
        printf("No path possible!\n");
        return;
    }
    if (i == j)
    {
        printf("%d", i);
    }
    else if (pathMatrix[i][j] == -1)
    {
        printf("No path possible!\n");
    }
    else
    {
        calculatePath(i, pathMatrix[i][j]);
        printf(" -> %d", j);
    }
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter adjacency matrix (use 0 or 999 for no edge):\n");
    for (int i = 1; i <= numNodes; i++)
    {
        for (int j = 1; j <= numNodes; j++)
        {
            int input;
            scanf("%d", &input);
            if (input == 0 && i != j)
                costMatrix[i][j] = INF;
            else
                costMatrix[i][j] = input;
        }
    }

    // printf("Enter source (1 to %d): ", numNodes);
    // scanf("%d", &source);
    // printf("Enter destination (1 to %d): ", numNodes);
    // scanf("%d", &destination);

    for (int i = 1; i <= numNodes; i++)
    {
        for (int j = 1; j <= numNodes; j++)
        {
            if (costMatrix[i][j] == INF || i == j)
                pathMatrix[i][j] = -1;
            else
                pathMatrix[i][j] = i;
        }
    }

    printf("\nInitial Cost Matrix:\n");
    printMatrix(costMatrix);
    printf("Initial Path Matrix:\n");
    printMatrix(pathMatrix);

    printf("Enter source (1 to %d): ", numNodes);
    scanf("%d", &source);
    printf("Enter destination (1 to %d): ", numNodes);
    scanf("%d", &destination);

    floydWarshall();

    printf("Final Cost Matrix:\n");
    printMatrix(costMatrix);
    printf("Final Path Matrix:\n");
    printMatrix(pathMatrix);

    printf("Shortest Path from %d to %d: ", source, destination);
    calculatePath(source, destination);
    printf("\nPath Cost: %d\n", costMatrix[source][destination]);

    return 0;
}
