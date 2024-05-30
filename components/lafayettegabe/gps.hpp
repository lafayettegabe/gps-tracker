#ifndef GPS_H
#define GPS_H

#include <string.h>
#include "esp_log.h"
#include "driver/gpio.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#define LED_PIN GPIO_NUM_2

static const char *TAG_GPS = "GPS";

class GPS {
    public:
        GPS();
        ~GPS();
        const json get_location();
};

GPS::GPS() {
    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG_GPS, "GPS initialized");
}

GPS::~GPS() {
    ESP_LOGI(TAG_GPS, "GPS destroyed");
}

const json GPS::get_location() {
    json location;
    
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);

    location["latitude"] = 37.7749;
    location["longitude"] = -122.4194;

    return location;
}

#endif