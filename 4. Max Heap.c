//4. Max Heap
#include <stdio.h>

void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

void heapify(int arr[], int n, int i)
{
    int max=i; 
    int left=2*i+1; 
    int right=2*i+2; 

    if (left<n && arr[left]>arr[max]) max=left;
    if (right<n && arr[right]>arr[max]) max=right;

    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

int main() {
    int arr[]={12, 11, 13, 5, 6, 7};
    int n=6;

    for (int i=n/2-1; i>=0; i--) heapify(arr, n, i);

    printf("Heap: ");
    for (int i=0;i<n;++i) printf("%d ",arr[i]);
    return 0;
}
