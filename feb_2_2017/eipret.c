#include <stdio.h>

void winner()
{
    printf("Congrats! You just hijacked EIP!\n");
    fflush(stdout);
    return;
}

int main()
{
    char buf[10];
    scanf("%s", buf);
    return 0;
}
