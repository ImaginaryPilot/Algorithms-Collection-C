#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]){
    int n;
    int max = 0;
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));
    int *out = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        out[i] = 0;
        if(arr[i] > max)
            max = arr[i];
    }
    max++;

    int *tmp = calloc(max, sizeof(int));
    for(int i = 0; i < n; i++)
        tmp[arr[i]]++;

    for(int i = 1; i < max; i++)
        tmp[i] += tmp[i-1]; 

    for(int i = n - 1; i >= 0; i--){
        out[tmp[arr[i]] - 1] = arr[i];
        tmp[arr[i]]--;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", out[i]);
    }
    printf("\n");

    free(arr);
    free(out);
    free(tmp);
    return 0;
}