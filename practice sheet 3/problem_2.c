#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, emi;
    int tenure;

    // Input the principal amount
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    // Input the annual interest rate (in percentage)
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);

    // Input the tenure (in months)
    printf("Enter the tenure (in months): ");
    scanf("%d", &tenure);

    // Convert annual interest rate to monthly interest rate
    float monthlyRate = rate / (12 * 100);

    // Calculate EMI using the formula:
    // EMI = [P * r * (1+r)^n] / [(1+r)^n - 1]
    emi = (principal * monthlyRate * pow(1 + monthlyRate, tenure)) / (pow(1 + monthlyRate, tenure) - 1);

    // Output the EMI
    printf("The EMI is: %.2f\n", emi);

    return 0;
}
