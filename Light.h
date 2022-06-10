#pragma once
#include <cstdint>
#include <stdint.h>

class Light {
private:
    bool on;
    uint16_t brightness;
public:
    Light();
    Light(bool on, uint16_t brightness);

    bool GetOn() const;
    uint16_t GetBrightness() const;

    void SetBrightness(uint16_t brightness);
    void Switch();
    void TurnOn();
    void TurnOff();
};