#include <stdio.h>
#include <stdlib.h>

int oddSerial; //1 if last num of serial num is odd

// signatures
void solveWire(void);
int yes(void);
int color(char *wires, char *color);
int main(void);

//implementations

int color(char *wires, char *color) {
    int result = 0;
    for (int i = 0; *(wires+i) != '\0'; i++) {
        if (*(wires+i) == *color) { result++; }
    }
    return result;
}

int yes(void) {
    char c;
    if ((c = getchar()) == 'y') {
        c = getchar();
        return 1;
    }
    c = getchar();
    return 0;
}

void solveWire(void) {
    printf("are there any wire modules? ");
    if (!yes()) { return; }
    printf("enter the wire config and press enter:  ");
    char c[7]; // list of wire colors
    int i = 0;
    while ((c[i]=getchar()) != '\n') {
        i++;
    }
    c[i] = '\0';
    if (i < 3 || i > 6) { 
        printf("error: too many or too few wires\n");
        solveWire();
    }

    int red; // red is r in c
    int white; // white is w in c
    int blue; // blue is b in c
    int yellow; // yellow is y in c
    int black; // black is k in c
    int k; // is there a black wire

    switch (i) {
        case 3:
            if ((red = color(c, "r")) == 0) {
                printf("cut the second wire\n");
                break;
            }
            blue = color(c, "c");
            if (*(c+2) == 'w' || blue < 2) {
                printf("cut the last wire\n");
                break;
            }
            printf("cut the last blue wire\n");
            break;
        case 4:
            red = color(c, "r");
            if (red > 1) {
                printf("is the last number of the serial number odd? ");
                if (yes()) {
                    printf("cut the last red wire\n");
                    break;
                }
                oddSerial = 0;
            }
            blue = color(c, "b");
            if ((blue == 1) || (red == 0 && *(c+3) == 'y')) {
                printf("cut the first wire\n");
                break;
            }
            yellow = color(c, "y");
            if (yellow > 1) {
                printf("cut the last wire\n");
                break;
            }
            printf("cut the second wire\n");
            break;
        case 5:
            if (*(c+4) == 'k') {
                k = 1;
                printf("is the last number of the serial number odd? ");
                if (yes()) {
                    printf("cut the last wire\n");
                    break;
                }
            }
            red = color(c, "r");
            yellow = color(c, "y");
            if (red == 0 && yellow > 1) {
                printf("cut the first wire\n");
                break;
            }
            if (k || color(c, "k")) {
                printf("cut the first wire\n");
                break;
            }
            printf("cut the second wire\n");
            break;
        case 6:
            yellow = color(c, "y");
            if (yellow == 0) {
                printf("is the last number of the serial number odd? ");
                if (yes()) {
                    printf("cut the third wire\n");
                    break;
                }
            }
            if ((color(c, "r")) || (yellow == 1 && color(c, "w") > 1)) {
                printf("cut the fourth wire\n");
                break;
            }
            printf("cut the last wire\n");
            break;
    }
    solveWire();
}

int main(void) {
    solveWire();

    return 0;
}