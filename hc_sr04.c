#include "hc_sr04.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "timer.h"
#include "uart.h"
#include "printf.h"


// Initialize the HC-SR04 sensor with given trigger and echo pins
hc_sr04_status_t hc_sr04_init(hc_sr04_sensor_t* sensor, gpio_id_t trigger_pin, gpio_id_t echo_pin) {
    if (!sensor) {
        return HC_SR04_ERROR_INIT_FAILED;
    }
    sensor->trigger_pin = trigger_pin;
    sensor->echo_pin = echo_pin;
    
    gpio_set_output(sensor->trigger_pin);
    gpio_set_input(sensor->echo_pin);
    gpio_set_pulldown(sensor->echo_pin);

    return HC_SR04_SUCCESS;
}

// Measure distance using the HC-SR04 sensor
hc_sr04_status_t hc_sr04_measure_distance(hc_sr04_sensor_t* sensor, int* distance) {
    if (!sensor || !distance) {
        return HC_SR04_ERROR_INIT_FAILED;
    }

    gpio_write(sensor->trigger_pin, 1);
    timer_delay_us(10); // pulse (set trigger high for 10 us)
    gpio_write(sensor->trigger_pin, 0);

    while (gpio_read(sensor->echo_pin) != 1);
    unsigned long start_tick = timer_get_ticks();
    while (gpio_read(sensor->echo_pin) == 1); // measure how long echo is held high (width of pulse)
    unsigned long usecs = (timer_get_ticks() - start_tick) / TICKS_PER_USEC;

    // Using 74 usec/inch as the speed of sound conversion factor
    int cm = usecs / 29;
    *distance = cm / 2; // divide by 2 to account for the round trip

    return HC_SR04_SUCCESS;
}

