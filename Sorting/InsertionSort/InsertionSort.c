#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
	return 0;
}
