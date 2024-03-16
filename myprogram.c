/*
 * HC-SR04 ultrasonic range sensor
 * Datasheet https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
 */
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

int abs(int n){
    if(n>=0){
        return n;
    }
    else{
        return -n;
    }
}


// Example main function to demonstrate usage
int main(void) {
    timer_init();
    gpio_init();
    uart_init();

    initializePinStraight();
    initializePinRight();
    initializePinLeft();

    gl_init(800, 600, GL_DOUBLEBUFFER);
    gl_clear(gl_color(0, 0, 0));

    hc_sr04_sensor_t left_sensor, right_sensor;
    int left_distance, right_distance;
    int left_distance_0, right_distance_0;
    hc_sr04_status_t left_status, right_status;
    // int prev_left, prev_right;
    // prev_left = prev_right = 130;

    // Initialize sensors with specific GPIO pins
    hc_sr04_init(&left_sensor, GPIO_PB3, GPIO_PB4); // Check these pin assignments
    hc_sr04_init(&right_sensor, GPIO_PB11, GPIO_PB12); // And these as well

    timer_delay_ms(1000);

    hc_sr04_status_t left_status_0 = hc_sr04_measure_distance(&left_sensor, &left_distance_0);
    hc_sr04_status_t right_status_0 = hc_sr04_measure_distance(&right_sensor, &right_distance_0);

    

    while (1) {

        while(1){
            display_initial();
            left_status = hc_sr04_measure_distance(&left_sensor, &left_distance);
            right_status = hc_sr04_measure_distance(&right_sensor, &right_distance);

            if (left_status != HC_SR04_SUCCESS || right_status != HC_SR04_SUCCESS){
                printf("Error reading sensor(s)\n");
            }

            if(abs(left_distance_0 - left_distance) >= 1 || abs(right_distance_0 - right_distance) >= 1){
                left_distance_0 = left_distance;
                right_distance_0 = right_distance;
                break;
            }
        }
       // gl_swap_buffer();

        // hc_sr04_status_t left_status = hc_sr04_measure_distance(&left_sensor, &left_distance);
        // hc_sr04_status_t right_status = hc_sr04_measure_distance(&right_sensor, &right_distance);

        // display_initial();

        display_zone(left_distance, right_distance);


        // if (left_status == HC_SR04_SUCCESS && right_status == HC_SR04_SUCCESS) {
        //     printf("Left = %d cm || Right = %d cm\n", left_distance, right_distance);

        //     display_zone(left_distance, right_distance);
        //     //timer_delay_ms(2000);
            

        // } else {
        //     // Handle error, for simplicity just printing an error message here
        //     printf("Error reading sensor(s)\n");
        // }
        // prev_left = left_distance;
        // prev_right = right_distance;

        // Optional: Add a delay to limit the rate of measurements
        // timer_delay_ms(100); // Delay for 500 milliseconds
    }

    return 0;
}

