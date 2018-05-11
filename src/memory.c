#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include "bomb.h"

void solveMemory(void) {
    printf("any memory modules? ");
    if (!yes()) { return; }

    //stage1
    int pos1;
    int label1;
    printf("enter # on display: ");
    switch (getNum()) {
        case 1:
            printf("press second position\n");
            pos1 = 2;
            break;
        case 2:
            printf("press second position\n");
            pos1 = 2;
            break;
        case 3:
            printf("press third position\n");
            pos1 = 3;
            break;
        case 4:
            printf("press fourth position\n");
            pos1 = 4;
            break;
    }
    printf("enter the label: ");
    label1 = getNum();

    //stage2
    int pos2;
    int label2;
    printf("enter # on display: ");
    switch(getNum()) {
        case 1:
            printf("press the button labeled 4\n");
            printf("enter the position: ");
            pos2 = getNum();
            label2 = 4;
            break;
        case 2:
            printf("press position %d\n", pos1);
            pos2 = pos1;
            printf("enter the label: ");
            label2 = getNum();
            break;
        case 3:
            printf("press position 1\n");
            pos2 = 1;
            printf("enter the label: ");
            label2 = getNum();
            break;
        case 4:
            printf("press position %d\n", pos1);
            pos2 = pos1;
            printf("enter the label: ");
            label2 = getNum();
            break;
    }

    //stage3
    int label3;
    printf("enter # on display: ");
    switch(getNum()) {
        case 1:
            printf("press the button labeled %d\n", label2);
            label3 = label2;
            break;
        case 2:
            printf("press the button labeled %d\n", label1);
            label3 = label1;
            break;
        case 3:
            printf("press position 3\n");
            printf("enter the label: ");
            label3 = getNum();
            break;
        case 4:
            printf("press the button labeled 4\n");
            label3 = 4;
            break;
    }

    //stage4
    int label4;
    printf("enter # on display: ");
    switch(getNum()) {
        case 1:
            printf("press position %d\n", pos1);
            break;
        case 2:
            printf("press position 1\n");
            break;
        case 3:
            printf("press position %d\n", pos2);
            break;
        case 4:
            printf("press position %d\n", pos2);
            break;
    }
    printf("enter the label: ");
    label4 = getNum();

    //stage5
    printf("enter # on display: ");
    switch(getNum()) {
        case 1:
            printf("press label %d\n", label1);
            break;
        case 2:
            printf("press label %d\n", label2);
            break;
        case 3:
            printf("press label %d\n", label3);
            break;
        case 4:
            printf("press label %d\n", label4);
            break;
    }

    solveMemory();
}

int getNum(void) {
    char c[2];
    c[0] = getchar();
    c[1] = getchar();
    c[1] = '\0';
    int i = atoi(c);
    return i;
}