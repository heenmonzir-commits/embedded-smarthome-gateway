# Hardware-Agnostic Smart Home Gateway 

A Modern C++ (C++11/14/17) implementation of a core Smart Home Gateway subsystem designed for resource-constrained Embedded Systems.

> ⚠️ **Note on Intellectual Property & NDA:** Due to non-disclosure agreements (NDA) and proprietary hardware protections, the actual physical peripheral drivers (I2C/SPI hardware abstraction implementations) and deployment configurations are omitted. This repository contains a decoupled production-grade core architecture utilizing an emulation layer to demonstrate design patterns, safety constraints, and memory management.

## 🛠️ Embedded Design Patterns & Architecture

- **Zero Dynamic Memory Allocation (Heapless Architecture):** Utilizes std::array and Stack Allocation instead of std::vector or raw dynamic pointers (new/delete). This completely eliminates Memory Fragmentation and guarantees deterministic real-time execution bounds.
- **Hardware Abstraction Layer (HAL):** Implements a clean, decoupled ISensor interface. This ensures the business logic remains fully agnostic of the specific underlying physical microcontroller chips or peripheral registers.
- **Bitwise Register Manipulation:** Simulates low-level hardware peripheral driver behavior by masking (&) and shifting (>>) raw bits from a 16-bit sensor register (e.g., extracting 12-bit ADC temperature data while validating 4-bit status flags).
- **Compile-time Constants:** Utilizes modern C++ templates to define registry bounds at compile time for maximum performance and runtime safety.
- **Memory & Exception Safety:** Functions are explicitly marked with noexcept and const where applicable to optimize binary size and enforce deployment safety constraints suitable for bare-metal or RTOS microcontrollers.

## 🏗️ Architecture Layout

[Physical Hardware / Peripheral Drivers] 
                  │ 
                  ▼ (Omitted due to NDA)
[Hardware Abstraction Layer (ISensor Interface)]
                  │ (update / printStatus)
                  ▼
[SmartHomeGateway (Central Control Loop)] --> Zero-Heap Registry

## 🚀 Compilation and Running

The core subsystem can be cross-compiled or tested locally using any standard C++ compiler (GCC / Clang):

g++ -std=c++11 main.cpp Sensors.cpp -o SmartHomeHub
./SmartHomeHub

### Expected Subsystem Output:
--- Initializing Hardware-Agnostic Smart Home System ---

--- Running Gateway Control Loop ---
[Smart Home Hub] Temperature Sensor: 40 C
[Smart Home Hub] Motion Sensor Status: MOTION DETECTED!
