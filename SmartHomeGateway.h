#ifndef SMARTHOMEGATEWAY_H
#define SMARTHOMEGATEWAY_H

#include "ISensor.h"
#include <array>
#include <cstddef>

template <size_t MAX_SENSORS>
class SmartHomeGateway {
private:
    std::array<ISensor*, MAX_SENSORS> sensorRegistry{};
    size_t sensorCount{0};

public:
    bool registerSensor(ISensor* sensor) noexcept {
        if (sensorCount >= MAX_SENSORS || sensor == nullptr) {
            return false;
        }
        sensorRegistry[sensorCount++] = sensor;
        return true;
    }

    void processAllSensors() noexcept {
        for (size_t i = 0; i < sensorCount; ++i) {
            if (sensorRegistry[i] != nullptr) {
                sensorRegistry[i]->update();
                sensorRegistry[i]->printStatus();
            }
        }
    }
};

#endif // SMARTHOMEGATEWAY_H
