#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, root1, root2, realPart, imaginaryPart;

    // Input coefficients a, b, and c
    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Real and unequal roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and unequal: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        // Real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal: %.2f and %.2f\n", root1, root2);
    } else {
        // Imaginary roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are imaginary: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
