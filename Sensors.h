#ifndef SENSORS_H
#define SENSORS_H

#include "ISensor.h"
#include <cstdint>

class SmartTemperatureSensor : public ISensor {
private:
    float currentTemperature{0.0f};
    bool sensorErrorFlag{false};
    uint16_t readHardwareRegister() const noexcept;

public:
    void update() noexcept override;
    void printStatus() const noexcept override;
};

class SmartMotionSensor : public ISensor {
private:
    bool motionDetected{false};
    uint8_t readGPIO_Pin() const noexcept;

public:
    void update() noexcept override;
    void printStatus() const noexcept override;
};

#endif // SENSORS_H
