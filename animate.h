#ifndef ANIMATE_H
#define ANIMATE_H

extern const char * pinStraight [18];
extern const char * pinRight [18];
extern const char * pinLeft [18];

void draw_ascii(const char *str, int x, int y);

void pin_reset();

void initializePinStraight();

void initializePinLeft();

void initializePinRight();

int display_falling_zone1();

int display_falling_zone2();

int display_falling_zone3();

int display_falling_zone4();

int display_falling_zone5();

int display_falling_zone6();

int display_falling_zone7();

int display_falling_zone8();

int display_falling_zone9();

int display_falling_zone10();

int display_falling_zone11();

int display_falling_zone12();

int display_falling_zone13();

int display_falling_zone14();

int display_falling_zone15();

int display_zone(int left_distance, int right_distance);

void clear(int x0, int y0, int x1, int y1);

#endif