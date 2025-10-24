#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getMax(int *arr, int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int *arr, int n, int max, int exp){
    
    int *out = calloc(n, sizeof(int));

    int *tmp = calloc(max, sizeof(int));
    for(int i = 0; i < n; i++)
        tmp[(arr[i] / exp) % 10]++;

    for(int i = 1; i < max; i++)
        tmp[i] += tmp[i-1]; 

    for(int i = n - 1; i >= 0; i--){
        out[tmp[(arr[i] / exp) % 10] - 1] = arr[i];
        tmp[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = out[i];

    free(out);
    free(tmp);
}

void radixSort(int *arr, int n){
    int max = getMax(arr, n);

    for(int i = 1; max / i > 0; i*=10)
        countSort(arr, n, max, i);
}

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}