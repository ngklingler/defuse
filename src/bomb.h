#ifndef BOMB_H
#define BOMB_H

extern int oddSerial; // 1 if last digit of serial number odd, 0 if not, -1 if not defined yet

// battery info
extern int batteries; // number of batteries, -1 if not defined

//indicators
extern int CAR; // 1 if car, 0 if not, -1 if not defined
extern int FRK; // 1 if car, 0 if not, -1 if not defined

int yes(void);

#endif