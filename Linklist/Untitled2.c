#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);

    int length = strlen(s);
    int sum = 0;

    for (int i = 0; i < length; i += 2) {
        sum += s[i] - '0'; // Convert character to integer
    }

    int output_length = (length + 1) / 2;
    char output[output_length];

    for (int i = 0, j = 0; i < length; i += 2, j++) {
        output[j] = s[i];
    }
    output[output_length - 1] = '\0';

    printf("%s\n", output);

    return 0;
}
