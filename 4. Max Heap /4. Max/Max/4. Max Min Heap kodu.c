//4. Max Min Heap kodu
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int n;
    int cap;
    int is_min;
} Heap;

Heap heap_new(int cap, int is_min);
void heap_free(Heap *h);
void heap_push(Heap *h, int v);
int heap_pop(Heap *h);

static int better(Heap *h, int x, int y){
    return h->is_min ? (x<y) : (x>y);
}
static void swap(int *x,int *y){ int t=*x; *x=*y; *y=t; }

int main(void){
    Heap h = heap_new(16, 0);
    heap_push(&h, 7);
    heap_push(&h, 2);
    heap_push(&h, 10);
    printf("%d\n", heap_pop(&h));
    heap_free(&h);
    return 0;
}

Heap heap_new(int cap, int is_min){
    Heap h;
    h.a = (int*)malloc(sizeof(int)*(size_t)cap);
    h.n=0; h.cap=cap; h.is_min=is_min;
    return h;
}
void heap_free(Heap *h){
    free(h->a); h->a=NULL; h->n=0; h->cap=0;
}
void heap_push(Heap *h, int v){
    if(h->n==h->cap){
        h->cap*=2;
        h->a=(int*)realloc(h->a,sizeof(int)*(size_t)h->cap);
    }
    int i=h->n++;
    h->a[i]=v;
    while(i>0){
        int p=(i-1)/2;
        if(better(h,h->a[i],h->a[p])){ swap(&h->a[i],&h->a[p]); i=p; }
        else break;
    }
}
int heap_pop(Heap *h){
    if(h->n==0) return 0;
    int root=h->a[0];
    h->a[0]=h->a[--h->n];
    int i=0;
    while(1){
        int l=2*i+1, r=2*i+2, best=i;
        if(l<h->n && better(h,h->a[l],h->a[best])) best=l;
        if(r<h->n && better(h,h->a[r],h->a[best])) best=r;
        if(best!=i){ swap(&h->a[i],&h->a[best]); i=best; }
        else break;
    }
    return root;
}
