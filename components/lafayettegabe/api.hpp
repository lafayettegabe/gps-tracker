#ifndef API_H
#define API_H

#include <string>
#include <nlohmann/json.hpp>
#include "esp_log.h"

static const char *TAG_API = "API";

class API {
public:
    API(std::string url);
    void post(nlohmann::json data);
private:
    std::string url;
};

API::API(std::string url) {
    this->url = url;
}

void API::post(nlohmann::json data) {
    ESP_LOGI(TAG_API, "Posting data to %s", this->url.c_str());
}

#endif