
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

const int ASCII_MIN = 32;
const int ASCII_MAX = 126;

void printHeader();
void printValidation();
int  stringLength(const char *str);
int  isValidString(const char *str);
void inputString(const char *prompt, char *str);
int  compareStrings(const char *s1, const char *s2);
int  firstDifference(const char *s1, const char *s2);
void pauseBeforeExit();

int main(void) {
    printHeader();
    printValidation();

    char first[MAX_LEN];
    char second[MAX_LEN];

    inputString("Please enter the first string:\n", first);
    inputString("Please enter the second string:\n", second);

    printf("\nString 1: \"%s\" (length: %d)\n", first, stringLength(first));
    printf("String 2: \"%s\" (length: %d)\n", second, stringLength(second));

    if (compareStrings(first, second)) {
        printf("Result: the strings are EQUAL.\n");
    } else {
        printf("Result: the strings are NOT equal.\n");
        printf("First difference at position: %d\n", firstDifference(first, second));
    }

    pauseBeforeExit();

    return 0;
}

void printHeader() {
    printf("Variant:\t6\nAuthor:\t\tArtem Cherednichenko\n");
    printf("Task: compare two strings \n\n");
}

void printValidation() {
    printf("Allowed characters: printable ASCII codes %d..%d\n", ASCII_MIN, ASCII_MAX);
    printf("Maximum length: %d characters\n\n", MAX_LEN - 1);
}

int stringLength(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int isValidString(const char *str) {
    int i = 0;

    if (str[0] == '\0') {
        printf("The string must not be empty. Please, try again.\n");
        return 0;
    }

    while (str[i] != '\0') {
        if ((unsigned char)str[i] < ASCII_MIN || (unsigned char)str[i] > ASCII_MAX) {
            printf("Invalid character at position %d. ", i + 1);
            printValidation();
            return 0;
        }
        i++;
    }

    return 1;
}

void inputString(const char *prompt, char *str) {
    int i, tooLong, valid;

    do {
        printf("%s", prompt);

        if (fgets(str, MAX_LEN, stdin) == NULL) {
            printf("Input stream closed. Exiting.\n");
            exit(EXIT_FAILURE);
        }

        tooLong = 1;
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == '\n') {
                str[i] = '\0';
                tooLong = 0;
                break;
            }
        }

        if (tooLong) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("The string is too long. Please, try again.\n");
            valid = 0;
        } else {
            valid = isValidString(str);
        }
    } while (!valid);

    printf("Your value was saved correctly.\n");
}

int compareStrings(const char *s1, const char *s2) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }

    return s1[i] == '\0' && s2[i] == '\0';
}

int firstDifference(const char *s1, const char *s2) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return i + 1;
        }
        i++;
    }

    if (s1[i] != '\0' || s2[i] != '\0') {
        return i + 1;
    }

    return 0;
}

void pauseBeforeExit() {
    printf("\nPress Enter to exit...");
    getchar();
}
