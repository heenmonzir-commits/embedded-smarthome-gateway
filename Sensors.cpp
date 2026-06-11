#include "Sensors.h"
#include <iostream>

uint16_t SmartTemperatureSensor::readHardwareRegister() const noexcept {
    return 0x0190;
}

void SmartTemperatureSensor::update() noexcept {
    uint16_t rawData = readHardwareRegister();
    uint16_t tempRaw = rawData & 0x0FFF;         
    uint8_t statusFlag = (rawData >> 12) & 0x0F; 
    
    if (statusFlag == 0x0) {
        sensorErrorFlag = false;
        currentTemperature = static_cast<float>(tempRaw) * 0.1f;
    } else {
        sensorErrorFlag = true; 
    }
}

void SmartTemperatureSensor::printStatus() const noexcept {
    std::cout << "[Smart Home Hub] Temperature Sensor: ";
    if (sensorErrorFlag) {
        std::cout << "ERROR (Hardware fault detected!)" << std::endl;
    } else {
        std::cout << currentTemperature << " C" << std::endl;
    }
}

uint8_t SmartMotionSensor::readGPIO_Pin() const noexcept {
    return 0x01; 
}

void SmartMotionSensor::update() noexcept {
    motionDetected = (readGPIO_Pin() & 0x01) == 0x01;
}

void SmartMotionSensor::printStatus() const noexcept {
    std::cout << "[Smart Home Hub] Motion Sensor Status: " 
              << (motionDetected ? "MOTION DETECTED!" : "No Motion") << std::endl;
}
