#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int comp(const void* a,const void* b) {
  	return *(int*)a - *(int*)b;
}

void twoSum(int *arr, int n, int target){
    int left = 0;
    int right = n - 1;

    while(left < right){
        int amount = arr[left] + arr[right];
        if(amount == target){
            printf("%d + %d = %d\n", arr[left], arr[right], target);
            return;
        }
        else if(amount > target)
            right--;
        else
            left++;
    }

    printf("Not Found\n");
}

int main(int argc, char *argv[]) {
    int n = 0, target;
    scanf("%d %d", &n, &target);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), comp);

    twoSum(arr, n, target);

    free(arr);
	return 0;
}
