#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int val;
    struct Node* next;
} node;

int getBucketIndex(int value, int interval){
    return value / interval;
}

void bucketSort(int* arr, int interval){
    struct Node **buckets = (struct Node**)malloc(10*sizeof(struct Node*));
}

int main(int argc, char *argv[]){
    int n, interval, nBuckets;
    int max = 0;
    scanf("%d %d %d", &n, &interval, &nBuckets);

    int *arr = malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }

    // bucketSort(arr, max / 10);

    // for(int i = 0; i < n; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");

    // for(int i = 0; i < 10; i++)
    //     free(buckets[i]);
    // free(buckets);
    // free(arr);
    return 0;
}