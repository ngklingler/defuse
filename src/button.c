#include <stdio.h>
#include <stdlib.h>
#include "bomb.h"

// extern vars
int oddSerial;
int CAR;
int FRK;

//button colors: [b]lue, [w]hite, [y]ellow
//buttons words: [a]bort, [d]etonate, [h]old

void solveButton(void) {
    //any buttons?
    printf("are there any buttons? ");
    if (!yes()) { return; }

    //get config
    printf("enter [c]olor [t]ext and press enter:  ");
    char button[3];
    int i = 0;
    while ((*(button+i) = getchar()) != '\n') {
        i++;
    }
    *(button+i) = '\0';

    //solve button
    while (1) {
        if (!strcmp(button, "ba")) {
        releaseButton();
        break;
        }
        if (*(button+1) == "d") {
            if (batteries == -1) {
                printf("how many batteries? ");
                char c[2];
                c[0] = getchar();
                c[1] = getchar();
                c[1] = '\0';
                batteries = atoi(c);
            }
            if (batteries > 1) {
                printf("press and release\n");
                break;
            }
        }
        if (*(button) == "w") {
            if (CAR == -1) {
                printf("any lit indicators that say CAR? ");
                if (yes()) { CAR = 1; }
                else { CAR = 0; }
            }
            if (CAR) {
                releaseButton();
                break;
            }
        }
        if (batteries == -1) {
            printf("how many batteries? ");
            char c[2];
            c[0] = getchar();
            c[1] = getchar();
            c[1] = '\0';
            batteries = atoi(c);
        }
        if (batteries > 2) {
            if (FRK == -1) {
                printf("any lit indicators that say FRK? ");
                if (yes()) { FRK = 1; }
                else { FRK = 0; }
            }
            if (FRK) {
                printf("press and release\n");
                break;
            }
        }
        if (*(button) == "y") {
            releaseButton();
            break;
        }
        if (!strcmp(button, "rh")) {
            printf("press and release\n");
            break;
        }
        releaseButton();
        break;
    }

    solveButton();
}

void releaseButton(void) {
    return;
}