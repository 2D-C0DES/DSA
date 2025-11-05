#include <stdio.h>
#include <math.h>

int isRamanujan(int num) {
    int count = 0;
    
    for (int i = 1; i <= cbrt(num); i++) {
        for (int j = i + 1; j <= cbrt(num); j++) {
            if ((i * i * i) + (j * j * j) == num) {
                count++;
                if (count == 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isRamanujan(num)) {
        printf("%d is a Ramanujan number.\n", num);
    } else {
        printf("%d is not a Ramanujan number.\n", num);
    }

    return 0;
}
