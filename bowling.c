#include "uart.h"
#include "animate.h"
#include "hc_sr04.h"
#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "mango.h"
#include "printf.h"
#include "ascii.h"


void main(void) {
    timer_init();
    gpio_init();
    uart_init();


    // hc_sr04_sensor_t left_sensor, right_sensor;
    // int left_distance, right_distance;

    // Initialize sensors with specific GPIO pins
    // hc_sr04_init(&left_sensor, GPIO_PB3, GPIO_PB4); // Check these pin assignments
    // hc_sr04_init(&right_sensor, GPIO_PB11, GPIO_PB12); // And these as well
    display_initial();
    // while (1) {

    //     hc_sr04_status_t left_status = hc_sr04_measure_distance(&left_sensor, &left_distance);
    //     hc_sr04_status_t right_status = hc_sr04_measure_distance(&right_sensor, &right_distance);


    //     if (left_status == HC_SR04_SUCCESS && right_status == HC_SR04_SUCCESS) {
    //         printf("Left = %d cm || Right = %d cm\n", left_distance, right_distance);
    //     } else {
    //         // Handle error, for simplicity just printing an error message here
    //         printf("Error reading sensor(s)\n");
    //     }

    //     // Optional: Add a delay to limit the rate of measurements
    //     // timer_delay_ms(500); // Delay for 500 milliseconds
    // }
}
