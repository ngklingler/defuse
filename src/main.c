#include "bomb.h"
#include "wire.h"
#include "button.h"
#include "memory.h"

//extern vars
int oddSerial = -1;
int batteries = -1;
int CAR = -1;
int FRK = -1;

int main(void) {
    solveWire();
    solveButton();
    solveMemory();

    return 0;
}