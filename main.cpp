#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "LightSystem.h"
#include "Utils.h"

int main() {
    std::vector<Light> data = loadLightsFromFile();
    LightSystem light_system = LightSystem(data);
    light_system.StartOperations();
}