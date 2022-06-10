#pragma once

#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <fstream>
#include "Light.h"

// Working with file
std::vector<Light> loadLightsFromFile();
void addLightToFile(Light light);
void dumpLightsToFile(std::vector<Light> lights);
// Validation
size_t inputId(size_t max);
bool inputOn();
uint16_t inputBrightness();