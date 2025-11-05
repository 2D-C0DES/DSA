#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool unique(char* string) {
    int length = strlen(string);
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if (string[i] == string[j]) {
                return false; // Return false if any duplicate is found
            }
        }
    }
    return true; // Return true if all characters are unique
}

int main() {
    int n;

    printf("Enter the size of the number: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    char str[n + 1]; // Allocate space for the string and null terminator
    printf("Enter the number: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if it's present
    str[strcspn(str, "\n")] = '\0';

    if(unique(str)) {
        printf("The number is unique.\n");
    } else {
        printf("The number is not unique.\n");
    }

    return 0;
}
