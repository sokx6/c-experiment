#include <stdio.h>
#include <string.h>

void clean_spaces(char *str) {
    char *out = str;
    int prev_space = 0;

    while (*str) {
        if (*str == ' ') {
            if (!prev_space) {
                *out++ = ' ';
                prev_space = 1;
            }
        } else {
            *out++ = *str;
            prev_space = 0;
        }
        str++;
    }

    *out = '\0';
}


int main() {
    char line[50];
    for (int i = 0; i < 5; i++) {
        fgets(line, sizeof(line), stdin);
        clean_spaces(line);
        printf("%s", line);
        if (line[strlen(line)-2] == '!' ) {
            break;
        }
    }
    return 0;
}