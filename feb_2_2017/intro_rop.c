#include <stdio.h>

void call_me(int a, int b) {
    printf("The provided value of a is: %d\n", a);
    printf("The provided value of b is: %d\n", b);
    
    int sum = a + b;

    printf("sum is: %d + %d = %d\n", a,b, sum);
    return;
}

void vuln() {
    char buf[50];
    scanf("%s", buf);
    return;
}

int main() {

    return 0;
}
