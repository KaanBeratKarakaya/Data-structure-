//7) Array’de ekleme-silme
#include <stdio.h>

int arr_insert(int a[], int *n, int cap, int idx, int v);
int arr_delete_at(int a[], int *n, int idx);

int main(void){
    int a[10]={1,2,4,5};
    int n=4;
    arr_insert(a,&n,10,2,3);
    arr_delete_at(a,&n,0);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

int arr_insert(int a[], int *n, int cap, int idx, int v){
    if(*n>=cap) return 0;
    if(idx<0 || idx>*n) return 0;
    for(int i=*n; i>idx; i--) a[i]=a[i-1];
    a[idx]=v;
    (*n)++;
    return 1;
}

int arr_delete_at(int a[], int *n, int idx){
    if(*n<=0) return 0;
    if(idx<0 || idx>=*n) return 0;
    for(int i=idx; i<*n-1; i++) a[i]=a[i+1];
    (*n)--;
    return 1;
}
