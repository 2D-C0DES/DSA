#include <stdio.h>

void computeSums(int num, int *sumDigits, int *sumEvenPlaces, int *sumOddPlaces) {
    int digit, place = 1;

    while (num > 0) {
        digit = num % 10;
        *sumDigits += digit;

        if (place % 2 == 0) {
            *sumEvenPlaces += digit;
        } else {
            *sumOddPlaces += digit;
        }

        num /= 10;
        place++;
    }
}

int main() {
    int num;
    int sumDigits = 0, sumEvenPlaces = 0, sumOddPlaces = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    computeSums(num, &sumDigits, &sumEvenPlaces, &sumOddPlaces);

    printf("Sum of digits: %d\n", sumDigits);
    printf("Sum of digits in even places: %d\n", sumEvenPlaces);
    printf("Sum of digits in odd places: %d\n", sumOddPlaces);

    return 0;
}
