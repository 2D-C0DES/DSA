#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;

    // Input the sides of the triangle
    printf("Enter the sides of the triangle:\n");
    scanf("%f %f %f", &a, &b, &c);

    // Check the validity of the triangle using the triangle inequality theorem
    if (a + b > c && b + c > a && c + a > b) {
        printf("The sides form a valid triangle.\n");

        // Calculate the semi-perimeter
        float s = (a + b + c) / 2;

        // Calculate the area using Heron's formula
        float area = sqrt(s * (s - a) * (s - b) * (s - c));

        // Output the area of the triangle
        printf("The area of the triangle is: %.2f\n", area);
    } else {
        printf("The sides do not form a valid triangle.\n");
    }

    return 0;
}
