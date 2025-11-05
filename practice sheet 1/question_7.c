#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, sum = 0, count = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    
    while (temp != 0) {
        temp /= 10;
        ++count;
    }

    temp = num;
    

    
    while (temp != 0) {
        remainder = temp % 10;
        sum +=(int)pow(remainder,count);
        temp /= 10;
        count--;
        
    }
    
    if (sum == num) {
        printf("%d is a weak Armstrong number.\n", num);
    } else {
        printf("%d is not a weak Armstrong number.\n", num);
    }

    return 0;
}