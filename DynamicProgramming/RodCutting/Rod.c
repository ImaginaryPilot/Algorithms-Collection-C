#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
   return (a > b) ? a : b;
}

int main(int argc, char *argv[]) {
    int n = 0;
    int finalPrice = 0;
    scanf("%d", &n);

    int *price = malloc((n+1)*sizeof(int));
    int *arr = malloc((n+1)*sizeof(int));

    for(int i = 1; i <= n; i++){
        scanf("%d", &price[i]);
        arr[i] = INT_MIN;
    }

    arr[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            arr[i] = max(arr[i], price[j] + arr[i - j]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] > finalPrice)
            finalPrice = arr[i];
    } 
    printf("%d\n", finalPrice);

    free(arr);
    free(price);
	return 0;
}
