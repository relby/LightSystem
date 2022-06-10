#pragma once
#include <iostream>
#include <stdint.h>
#include <vector>
#include <cstdint>
#include <string>
#include "Light.h"
#include "Utils.h"

class LightSystem {
private:
    std::vector<Light> lights;

    uint16_t ChooseOperation();
    void LightsStatus();
    void AddLight();
    void TurnOffLights();
    void TurnOnLights();
    void SwitchLight();
    void SetBrightessOfLight();
    void DeleteLight();
public:
    LightSystem(const std::vector<Light> data);
    void StartOperations();
};
