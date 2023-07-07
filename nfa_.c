#include <stdio.h>
int current=0;
void q0(char c) {
    if (c == '0')
        current = 1;
    else
        current = -1;
}

void q1(char c) {
    if (c == '1')
        current = 2;
    else
        current = -1;
}

void q2(char c) {
    if (c == '0' || c == '1')
        current = 2;
    else
        current = -1;
}

int main() {
    char input_str[20], c;
  //  int current = 0;
    int i = 0;

    printf("Enter an input string: ");
    scanf("%s", input_str);

    c = input_str[i];

    while (c != '\0') {
        switch (current) {
            case 0:
                q0(c);
                break;
            case 1:
                q1(c);
                break;
            case 2:
                q2(c);
                break;
        }
        c = input_str[++i];
    }

    printf("%d", current);

    if (current == 2) {
        printf("\nAccepted");
    } else {
        printf("\nRejected");
    }

    return 0;
}
