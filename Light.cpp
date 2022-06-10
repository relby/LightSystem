#include "Light.h"

Light::Light() : on(false), brightness(100) {}
Light::Light(bool on, uint16_t brightness): on(on), brightness(brightness) {}
bool Light::GetOn() const {
    return this->on;
}
uint16_t Light::GetBrightness() const {
    return this->brightness;
}
void Light::SetBrightness(uint16_t brightness) {
    this->brightness = brightness;
}
void Light::Switch() {
    this->on = !this->on;
};
void Light::TurnOn() {
    this->on = true;
}
void Light::TurnOff() {
    this->on = false;
}
