#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int crossingSubArray(int *arr, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = -1, maxRight = -1;
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum += arr[i];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }
    return (leftSum + rightSum);
}

int maxSubArray(int *arr, int low, int high){
    if(low == high)
        return arr[low];
    else {
        int mid = (low + high)/2;
        int leftSum = maxSubArray(arr, low, mid);
        int rightSum = maxSubArray(arr, mid + 1, high);
        int midSum = crossingSubArray(arr, low, mid, high);
        if(leftSum >= rightSum && leftSum >= midSum)
            return leftSum;
        else if(rightSum >= leftSum && rightSum >= midSum)
            return rightSum;
        else 
            return midSum;
    }
}

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxSubArray(arr, 0, n - 1));

    free(arr);
	return 0;
}
