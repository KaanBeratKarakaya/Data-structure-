//2. Hanoi Tower
#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if(n==1) {
        printf("Disk 1: %c -> %c\n", a, b);
        return;
    }
    
    hanoi(n-1, a, c, b);
    printf("Disk %d: %c -> %c\n", n, a, b);
    hanoi(n-1, c, b, a);
}

int main() {
    int n;
    printf("Disk sayisi: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
