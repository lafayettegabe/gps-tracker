idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES components esp_wifi nvs_flash driver)