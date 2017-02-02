#include <stdio.h>

// Try to call this function
// Hint: gdb eipret
void winner()
{
    printf("Congrats! You just hijacked EIP!\n");
    fflush(stdout);
    return;
}

// Vulnerable function
void vuln() 
{
	char buf[100];
    scanf("%s", buf);
	return;
}


int main()
{
    vuln(); 
    return 0;
}
