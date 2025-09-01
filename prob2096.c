//decend 내려가기
#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int n;
    int input[3] = {0, };
    int min[3] = {0, 0, 0};
    int max[3] = {0, 0, 0};
    int temp[3] = {0, 0, 0};


    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", input, input+1, input+2);
        
        // find min value
        if (min[0] < min[1])
        {
            temp[0] = min[0]+input[0];
            if (min[1] < min[2]) {
                temp[1] = min[0]+input[1];
                temp[2] = min[1]+input[2];
            } else {
                temp[2] = min[2]+input[2];
                if (min[0] < min[2])
                {
                    temp[1] = min[0]+input[1];
                } else {
                    temp[1] = min[2]+input[1];
                }
            }
        } else if (min[1] < min[2]) { // min[0] >= min[1]
            temp[0] = min[1]+input[0];
            temp[1] = min[1]+input[1];
            temp[2] = min[1]+input[2];
        } else {
            // min[0] >= min[1] && min[1] >= min[2]
            temp[0] = min[1]+input[0];
            temp[1] = min[2]+input[1];
            temp[2] = min[2]+input[2];
        }
        min[0] = temp[0];
        min[1] = temp[1];
        min[2] = temp[2];
        
        // find max value
        if (max[0] > max[1])
        {
            temp[0] = max[0]+input[0];
            if (max[1] > max[2]) {
                temp[1] = max[0]+input[1];
                temp[2] = max[1]+input[2];
            } else {
                temp[2] = max[2]+input[2];
                if (max[0] > max[2])
                {
                    temp[1] = max[0]+input[1];
                } else {
                    temp[1] = max[2]+input[1];
                }
            }
        } else if (max[1] > max[2]) { // max[0] <= max[1]
            temp[0] = max[1]+input[0];
            temp[1] = max[1]+input[1];
            temp[2] = max[1]+input[2];
        } else {
            // max[0] <= max[1] && max[1] <= max[2]
            temp[0] = max[1]+input[0];
            temp[1] = max[2]+input[1];
            temp[2] = max[2]+input[2];
        }
        max[0] = temp[0];
        max[1] = temp[1];
        max[2] = temp[2];
    }
    int min_res, max_res;
    if (max[0]>max[1]) {
        if (max[0] > max[2]) {
            max_res = max[0];
        } else{
            max_res = max[2];
        }
    } else {
        if (max[1] > max[2]) {
            max_res = max[1];
        } else{
            max_res = max[2];
        }
    }
    if (min[0]<min[1]) {
        if (min[0] < min[2]) {
            min_res = min[0];
        } else{
            min_res = min[2];
        }
    } else {
        if (min[1] < min[2]) {
            min_res = min[1];
        } else{
            min_res = min[2];
        }
    }
    printf("%d %d\n", max_res, min_res);

    return 0;
}