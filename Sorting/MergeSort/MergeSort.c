#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right){
    int i, j, k;

    int leftHalf = mid - left;
    int rightHalf = right - mid;

    int L[leftHalf];
    int R[rightHalf];

    for(int i = 0; i < leftHalf; i++){
        L[i] = arr[left+i];
    }

    for(int j = 0; j < rightHalf; j++){
        R[j] = arr[mid + j];
    }

    i = 0;
    j = 0;
    k = left;
    while(i < leftHalf && j < rightHalf){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i < leftHalf){
        arr[k++] = L[i++];
    }

    while(j < rightHalf){
        arr[k++] = R[j++];
    }
}

void mergeSort(int *arr, int left, int right){
    if(left < right - 1){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
	return 0;
}
