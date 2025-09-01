// get least cost
#include<stdio.h>
#include<stdlib.h>

#define INIT_COST 4000000000000000000

int main(void) {
    int n=0, m=0;
    scanf("%d", &n);
    scanf("%d", &m);

    int start, end, cost;
    long long int cost_mat[1001][1001] = {0, };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost_mat[i][j] = INIT_COST;
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &start, &end, &cost);
        cost_mat[start][end] = cost>cost_mat[start][end]?cost_mat[start][end]:cost;
        
        for (int j = 1; j <= n; j++)
        {
            cost_mat[start][j] = cost+cost_mat[end][j]>cost_mat[start][j]?
                cost_mat[start][j]:cost+cost_mat[end][j];
            cost_mat[j][end] = cost_mat[j][start]+cost>cost_mat[j][end]?
                cost_mat[j][end]:cost_mat[j][start]+cost;
        }
    }
    
    scanf("%d %d", &start, &end);
    printf("%lld\n", cost_mat[start][end]);

    return 0;
}