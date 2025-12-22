//10) Array kullanarak tree creation
#include <stdio.h>

void preorder(int a[], int n, int i){
    if(i>=n) return;
    printf("%d ", a[i]);
    preorder(a,n,2*i+1);
    preorder(a,n,2*i+2);
}

int main(void){
    int a[]={10,5,15,2,7,12,20};
    int n=7;
    preorder(a,n,0);
    printf("\n");
    return 0;
}
