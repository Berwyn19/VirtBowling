#ifndef HC_SR04_H
#define HC_SR04_H

#include <stdint.h>
#include <gpio.h>


// Status codes for the HC-SR04 functions
typedef enum {
    HC_SR04_SUCCESS = 0,
    HC_SR04_ERROR_TIMEOUT,
    HC_SR04_ERROR_INIT_FAILED,
} hc_sr04_status_t;

// Structure to represent an HC-SR04 sensor instance.
typedef struct {
    uint8_t trigger_pin; // GPIO pin number used for the trigger
    uint8_t echo_pin;    // GPIO pin number used for the echo
} hc_sr04_sensor_t;

// Initializes an HC-SR04 sensor instance.
// Parameters:
//  - sensor: Pointer to an hc_sr04_sensor_t structure to be initialized
//  - trigger_pin: The GPIO pin connected to the sensor's trigger
//  - echo_pin: The GPIO pin connected to the sensor's echo
// Returns: hc_sr04_error_t indicating the status of the operation
hc_sr04_status_t hc_sr04_init(hc_sr04_sensor_t* sensor, gpio_id_t trigger_pin, gpio_id_t echo_pin);

// Performs a distance measurement with an HC-SR04 sensor.
// Parameters:
//  - sensor: Pointer to an initialized hc_sr04_sensor_t structure
//  - distance: Pointer to a imt variable to store the measured distance (in centimeters)
// Returns: hc_sr04_error_t indicating the status of the operation
hc_sr04_status_t hc_sr04_measure_distance(hc_sr04_sensor_t* sensor, int* distance);

#endif // HC_SR04_H
