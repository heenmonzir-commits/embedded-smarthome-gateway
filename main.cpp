#include <iostream>
#include "SmartHomeGateway.h"
#include "Sensors.h"

int main() {
    std::cout << "--- Initializing Hardware-Agnostic Smart Home System ---" << std::endl;

    SmartTemperatureSensor livingRoomTemp;
    SmartMotionSensor frontDoorMotion;

    SmartHomeGateway<5> homeGateway;

    homeGateway.registerSensor(&livingRoomTemp);
    homeGateway.registerSensor(&frontDoorMotion);

    std::cout << "\n--- Running Gateway Control Loop ---" << std::endl;
    homeGateway.processAllSensors();

    return 0;
}
