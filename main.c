#include<stdio.h>
#include<stdlib.h>

int list(int arr[], int n, int *max_ref);
int x(int arr[], int n);

int main(){
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Largest ascending list we can make is with %d numbers.", x(arr, n));
    return 0;
}

int list(int arr[], int n, int *max_ref){
    if (n == 1){
        return 1;
    }

    int res, max_ending_here = 1;

    for (int i = 1; i < n; i++){
        res = list(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here){
            max_ending_here = res + 1;
        }
    }

    if (*max_ref < max_ending_here){
       *max_ref = max_ending_here;
    }

    return max_ending_here;
}

int x(int arr[], int n){
    int max = 1;
    list(arr, n, &max);
    return max;
}
