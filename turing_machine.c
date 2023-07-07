#include <stdio.h>
#include <string.h>

int main() {
    char tape[100];
    printf("Enter the input string (a's and b's): ");
    scanf("%s", tape);

    int i = 0;
    int aCount = 0;
    int bCount = 0;

    // Count the number of 'a's
    while (tape[i] == 'a') {
        aCount++;
        i++;
    }

    // Count the number of 'b's
    while (tape[i] == 'b') {
        bCount++;
        i++;
    }

    // Check if the remaining symbols are 'b's and the counts match
    if (tape[i] == '\0' && aCount > 0 && aCount == bCount) {
        printf("Input follows the pattern a^n b^n.\n");
    } else {
        printf("Input does not follow the pattern a^n b^n.\n");
    }

    return 0;
}
