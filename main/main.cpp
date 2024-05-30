#include <lafayettegabe/wifi_manager.hpp>
#include <lafayettegabe/gps.hpp>

static const char *TAG = "Tracker";

void stream_location(void *pvParameters);

extern "C" void app_main(void)
{
    WiFiManager wifiManager;
    wifiManager.connect();

    xTaskCreate(stream_location, "stream_location", 4096, NULL, 6, NULL);
}

void stream_location(void *pvParameters) {
    GPS gps;
    while (true) {
        json location = gps.get_location();
        ESP_LOGI(TAG, "%s", location.dump().c_str());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}