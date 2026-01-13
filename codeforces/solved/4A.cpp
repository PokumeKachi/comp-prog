#include <stdio.h>

int a;

int main() {
    scanf("%d", &a);

    printf((a % 2 == 0) ? "YES" : "NO");

    return 0;
}
