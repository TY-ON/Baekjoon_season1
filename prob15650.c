//N과M (2)
#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    // set init;
    int arr[9] = {
        0,
    };
    for (int i = 0; i < m; i++)
    {
        arr[i] = m - i;
    }

    int index = 0;
    arr[index]--;
    while (index < m)
    {
        arr[index]++;
        if (arr[index] > n - index)
        {
            index++;
        } else {
            index--;
            if (index < 0)
            {
                index = 0;
                print_arr(arr, m);
            } else {
                arr[index] = arr[index+1];
            }
        }
    }

    return 0;
}