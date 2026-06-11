#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual void update() noexcept = 0;
    virtual void printStatus() const noexcept = 0;
};

#endif // ISENSOR_H
