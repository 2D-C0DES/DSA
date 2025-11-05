#include <stdio.h>

int main() {
    int units;
    printf("Enter the total number of units consumed: ");
    scanf("%d", &units);

    double bill = 0.0;

    // First 25 units at 3 rupees per unit
    if (units > 25) {
        bill += 25 * 3.0;
        units -= 25;
    } else {
        bill += units * 3.0;
        units = 0;
    }

    // Next 10 units at 4 rupees per unit
    if (units > 10) {
        bill += 10 * 4.0;
        units -= 10;
    } else {
        bill += units * 4.0;
        units = 0;
    }

    // Next 10 units at 5 rupees per unit
    if (units > 10) {
        bill += 10 * 5.0;
        units -= 10;
    } else {
        bill += units * 5.0;
        units = 0;
    }

    // Next 10 units at 6 rupees per unit
    if (units > 10) {
        bill += 10 * 6.0;
        units -= 10;
    } else {
        bill += units * 6.0;
        units = 0;
    }

    // Rest of the units at 7 rupees per unit
    if (units > 0) {
        bill += units * 7.0;
    }

    printf("Your electricity bill is: %.2f rupees\n", bill);

    return 0;
}