#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "mango.h"
#include "uart.h"
#include "printf.h"
#include "hc_sr04.h"
#include "gl.h"
#include "animate.h"
#include "utils.h"
#include "game.h"
#include "keyboard.h"
#include "interrupts.h"
#include "malloc.h"
#include "scoreboard.h"

void draw_scoreboard_boilerplate(void) {
    printf("Inside the boilerplate function\n");
    gl_draw_line(0, 0, 0, 40, GL_WHITE);
    gl_draw_line(0, 0, 800, 0, GL_WHITE);
    gl_draw_line(0, 40, 800, 40, GL_WHITE);
    gl_draw_line(800, 0, 800, 40, GL_WHITE);
    gl_draw_line(0, 20, 800, 20, GL_WHITE);
    for (int i = 0; i < 21; i++) {
        gl_draw_line(140 + 15 * i, 0, 140 + 15 * i, 40, GL_WHITE);
    }
}