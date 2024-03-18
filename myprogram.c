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
#include "game.h"
#include "keyboard.h"
#include "interrupts.h"
#include "malloc.h"
#include "scoreboard.h"

int abs(int n){
    if(n >= 0){
        return n;
    }
    else{
        return -n;
    }
}
// Example main function to demonstrate usage
int count = 0;

int main(void) {
    timer_init();
    gpio_init();
    uart_init();
    interrupts_init();
    keyboard_init(GPIO_PG12, GPIO_PB7);
    interrupts_global_enable();

    initializePinStraight();
    initializePinRight();
    initializePinLeft();

    gl_init(800, 600, GL_DOUBLEBUFFER);
    gl_clear(gl_color(0, 0, 0));


    // Declaring The necessary variables.
    hc_sr04_sensor_t left_sensor, right_sensor;
    int left_distance, right_distance;

    int left_distance_0, right_distance_0;
    // int left_distance_0 = 162;
    hc_sr04_status_t left_status, right_status;
    // hc_sr04_status_t left_status;
    // int prev_left, prev_right;
    // prev_left = prev_right = 130;

    //Initialize sensors with specific GPIO pins
    hc_sr04_init(&left_sensor, GPIO_PB3, GPIO_PB4); // Check these pin assignments
    hc_sr04_init(&right_sensor, GPIO_PB11, GPIO_PB12); // And these as well

    timer_delay_ms(1000);

    hc_sr04_status_t left_status_0 = hc_sr04_measure_distance(&left_sensor, &left_distance_0);
    hc_sr04_status_t right_status_0 = hc_sr04_measure_distance(&right_sensor, &right_distance_0);

    // char ** players = start_game();
    int struct_size = 5 * sizeof(int) + 10 * sizeof(char) + sizeof(int);

    struct Player * player1 = malloc(struct_size);
    struct Player * player2 = malloc(struct_size);

    // player1->name = players[0];
    // player2->name = players[1];

    // player1->score = malloc(5 * sizeof(int));
    // player2->score = malloc(5 * sizeof(int));

    player1->round = 0;
    player2->round = 0;

    while (1) {
        while(1){
            // Setup the state for the game
            display_turn(count, "Berwyn", "Sazzad");
            pin_reset();

            // Measure the distance, and take the status from the sensor.
            left_status = hc_sr04_measure_distance(&left_sensor, &left_distance);
            right_status = hc_sr04_measure_distance(&right_sensor, &right_distance);

            // Return error if the sensor's fail to read
            if (left_status != HC_SR04_SUCCESS || right_status != HC_SR04_SUCCESS){
                printf("Error reading sensor(s)\n");
            }


            if(abs(left_distance_0 - left_distance) >= 10 || abs(right_distance_0 - right_distance) >= 10){
                left_distance_0 = left_distance;
                right_distance_0 = right_distance;
                break;
            }

        }
        int score = display_zone(left_distance, 0);

        if ((count % 2) == 0) {
            (player1->score)[player1->round] = score;
            player1->round++;
        }

        else if ((count % 2) == 1) {
            (player2->score)[player2->round] = score;
            player2->round++;
        }

        count++;
    }
    free(player1);
    free(player2);
    // free(players);
    return 0;
}

