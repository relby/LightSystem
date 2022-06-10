#include "LightSystem.h"
#include <stdint.h>

LightSystem::LightSystem(const std::vector<Light> data) {
    for (const Light& light : data) {
        this->lights.push_back(light);
    }
}

void LightSystem::LightsStatus() {
    for (size_t i = 0; i < this->lights.size(); i++) {
        Light light = this->lights[i];
        std::string status = light.GetOn() ? "on" : "off";
        std::cout << "Light #" << i << " Status: " << status << " Brightness: " << light.GetBrightness() << '\n';
    }
};

void LightSystem::AddLight() {
    bool on = inputOn();
    uint16_t brightness = inputBrightness();
    Light light(on, brightness);
    this->lights.push_back(light);
    addLightToFile(light);
};

void LightSystem::TurnOffLights() {
    for (Light& light : this->lights) {
        light.TurnOff();
    }
}

void LightSystem::TurnOnLights() {
    for (Light& light : this->lights) {
        light.TurnOn();
    }
}

void LightSystem::SwitchLight() {
    size_t id = inputId(this->lights.size() - 1);
    this->lights[id].Switch();
}
void LightSystem::SetBrightessOfLight() {
    size_t id = inputId(this->lights.size() - 1);
    uint16_t brightness = inputBrightness();
    this->lights[id].SetBrightness(brightness);
}

void LightSystem::DeleteLight() {
    size_t id = inputId(this->lights.size() - 1);
    this->lights.erase(this->lights.begin() + id);
}

void LightSystem::StartOperations() {
    bool quit = false;
    while (!quit) {
        uint8_t operation = this->ChooseOperation();
        switch (operation) {
        case 0:  // Lights status
            this->LightsStatus();
            break;
        case 1: // Add light
            this->AddLight();
            break;
        case 2:
            this->TurnOffLights();
            dumpLightsToFile(this->lights);
            break;
        case 3:
            this->TurnOnLights();
            dumpLightsToFile(this->lights);
            break;
        case 4:
            this->SwitchLight();
            dumpLightsToFile(this->lights);
            break;
        case 5:
            this->SetBrightessOfLight();
            dumpLightsToFile(this->lights);
            break;
        case 6:
            this->DeleteLight();
            dumpLightsToFile(this->lights);
            break;
        case 7: {      // Quit
            quit = true;
            break;
        }
        }
    }
}

// private

uint16_t LightSystem::ChooseOperation() {
    uint16_t input = -1;
    std::cout << "Choose the operation:\n";
    std::cout << "[0]: Lights status\n";
    std::cout << "[1]: Add light\n";
    std::cout << "[2]: Turn off all lights\n";
    std::cout << "[3]: Turn on all lights\n";
    std::cout << "[4]: Switch the light\n";
    std::cout << "[5]: Set brightness of the light\n";
    std::cout << "[6]: Delete light\n";
    std::cout << "[7]: Quit\n";
    while (input > 7) {
        std::cin >> input;
    }
    return input;
};