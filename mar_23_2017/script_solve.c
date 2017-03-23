#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// This one should be fairly straightforward
// Simply script to grab and repeat the appropriate 
// response

int main() {
    srand(time(NULL));
    int num = rand();
    int resp;
    int count = 0;

    for (count = 0; count < 1000; count++) {
        printf("The number is: %d\n", num);
        printf("Please enter the number: \n");
        scanf("%d", &resp);
        if(resp != num) {
            printf("FAIL!\n");
            exit(1);
        }
        
        num = rand();

    }

    printf("WINNER WINNER");
    return 0;
}
