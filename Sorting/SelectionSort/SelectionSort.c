#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n - 1; i++){
        int key = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[key]){
                key = j;
            }
        }

        if(key != i)
            swap(&arr[key], &arr[i]);
    }

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
	return 0;
}
