#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double A_MIN = -1.0e+6;
const double A_MAX =  1.0e+6;

const int MODE_DEGREES = 1;
const int MODE_RADIANS = 2;

void printHeader();
void printValidation();
void printModes();
int inputMode();
double inputNumber();
double degreesToRadians(double deg);
double calculateZ1(double a);
double calculateZ2(double a);
void pauseBeforeExit();

int main(void) {
    printHeader();

    int mode;
    double a, aRad;

    printModes();
    mode = inputMode();

    printValidation();
    printf("Please enter alpha:\n");
    a = inputNumber();

    if (mode == MODE_DEGREES) {
        aRad = degreesToRadians(a);
        printf("alpha = %lf deg = %lf rad\n", a, aRad);
    } else {
        aRad = a;
        printf("alpha = %lf rad = %lf deg\n", aRad, aRad * 180.0 / M_PI);
    }

    printf("z1 = %lf\n", calculateZ1(aRad));
    printf("z2 = %lf\n", calculateZ2(aRad));

    pauseBeforeExit();

    return 0;
}

void printHeader() {
    printf("Variant:\t6\nAuthor:\t\tCherednichenko\n");
    printf("z1 = cos(a) + cos(2a) + cos(6a) + cos(7a)\n");
    printf("z2 = 4 * cos(a/2) * cos(5a/2) * cos(4a)\n\n");
}

void printValidation() {
    printf("Range of permissible values: [%.lf;%.lf]\n", A_MIN, A_MAX);
}

void printModes() {
    printf("Choose angle units:\n");
    printf("  %d - degrees\n", MODE_DEGREES);
    printf("  %d - radians\n", MODE_RADIANS);
}

int inputMode() {
    int mode;
    char check = 0;

    do {
        if (scanf("%d%c", &mode, &check) != 2 || check != '\n') {
            printf("Invalid number. Please, try again.\n");
            while (getchar() != '\n');
        } else {
            if (mode != MODE_DEGREES && mode != MODE_RADIANS) {
                printModes();
                check = 0;
            }
        }
    } while (check != '\n');

    return mode;
}

double inputNumber() {
    double a;
    char check = 0;

    do {
        if (scanf("%lf%c", &a, &check) != 2 || check != '\n') {
            printf("Invalid number. Please, try again.\n");
            while (getchar() != '\n');
        } else {
            if (!(a >= A_MIN && a <= A_MAX)) {
                printValidation();
                check = 0;
            }
        }
    } while (check != '\n');

    printf("Your value was saved correctly.\n");
    return a;
}

double degreesToRadians(double deg) {
    return deg * M_PI / 180.0;
}

double calculateZ1(double a) {
    return cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
}

double calculateZ2(double a) {
    return 4 * cos(a / 2) * cos(5 * a / 2) * cos(4 * a);
}

void pauseBeforeExit() {
    printf("\nPress Enter to exit...");
    getchar();
}
