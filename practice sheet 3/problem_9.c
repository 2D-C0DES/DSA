#include <stdio.h>

// Function to calculate income tax
float calculateTax(float income, int age) {
    float tax = 0.0;

    // Senior citizens
    if (age >= 60) {
        if (income <= 300000) {
            tax = 0;
        } else if (income <= 500000) {
            tax = (income - 300000) * 0.05;
        } else if (income <= 1000000) {
            tax = 10000 + (income - 500000) * 0.10;
        } else {
            tax = 50000 + (income - 1000000) * 0.20;
        }
    }
    // Non-senior citizens
    else {
        if (income <= 250000) {
            tax = 0;
        } else if (income <= 500000) {
            tax = (income - 250000) * 0.05;
        } else if (income <= 1000000) {
            tax = 12500 + (income - 500000) * 0.10;
        } else {
            tax = 50000 + (income - 1000000) * 0.20;
        }
    }

    return tax;
}

int main() {
    float income;
    int age;

    printf("Enter your income: ");
    scanf("%f", &income);

    printf("Enter your age: ");
    scanf("%d", &age);

    float tax = calculateTax(income, age);

    printf("Your income tax is: %.2f\n", tax);

    return 0;
}