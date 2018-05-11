#include "bomb.h"
#include <stdio.h>

int yes(void) {
    char c;
    if ((c = getchar()) == 'y') {
        c = getchar();
        return 1;
    }
    c = getchar();
    return 0;
}