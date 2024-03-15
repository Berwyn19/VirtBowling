#include "uart.h"
#include "animate.h"
#include "hc_sr04.h"
#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "mango.h"
#include "printf.h"
#include "gl.h"

static void pause(const char *message) {
    if (message) printf("\n%s\n", message);
    printf("[PAUSED] type any key in minicom/terminal to continue: ");
    int ch = uart_getchar();
    uart_putchar(ch);
    uart_putchar('\n');
}



void main(void) {
    timer_init();
    gpio_init();
    uart_init();

    initializePinStraight();
    initializePinRight();
    initializePinLeft();
    
    gl_init(800, 600, GL_DOUBLEBUFFER);
    gl_clear(gl_color(0, 0, 0));
    // const char * pinStraight[18];
    // const char * pinRight[18];
    // const char * pinLeft[18];
    hc_sr04_sensor_t left_sensor, right_sensor;
    int left_distance, right_distance;

    // Initialize sensors with specific GPIO pins
    hc_sr04_init(&left_sensor, GPIO_PB3, GPIO_PB4); // Check these pin assignments
    hc_sr04_init(&right_sensor, GPIO_PB11, GPIO_PB12); // And these as well
}
