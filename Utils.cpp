#include "Utils.h"
#include <fstream>

std::vector<Light> loadLightsFromFile() {
    std::ifstream file;
    file.open("data.csv", std::fstream::app);
    if (!file.is_open()) {
        std::cerr << "ERROR: data.csv hasn't opened\n";
        exit(1);
    }
    std::string s;
    std::vector<Light> out;
    while (std::getline(file, s)) {
        if (s == "") continue;
        size_t a = s.find(',');
        bool on = s.substr(0, a) == "true" ? true : false;
        uint16_t brightness = std::stoi(s.substr(a + 1, s.size() - a - 1));
        out.push_back(Light(on, brightness));
    }
    file.close();
    return out;
}

void addLightToFile(Light light) {
    std::ofstream file;
    file.open("data.csv", std::fstream::app);
    if (!file.is_open()) {
        std::cerr << "ERROR: data.csv hasn't opened\n";
        exit(1);
    }
    std::string on = light.GetOn() ? "true" : "false";
    std::string brightness = std::to_string(light.GetBrightness());
    file << '\n' << on << ',' << brightness << '\n';
    file.close();
}

void dumpLightsToFile(std::vector<Light> lights) {
    std::ofstream file;
    file.open("data.csv", std::fstream::out | std::fstream::trunc);
    if (!file.is_open()) {
        std::cerr << "ERROR: data.csv hasn't opened\n";
        exit(1);
    }
    for (const Light& light : lights) {
        addLightToFile(light);
    }
}

size_t inputId(size_t max) {
    size_t in = -1;
    std::cout << "Enter id of the light (0-" << max << ")\n";
    while (in > max) {
        std::cin >> in;
    }
    return in;
}

bool inputOn() {
    std::string in = "";
    std::cout << "Enter on (true/false): ";
    while (in != "true" && in != "false") {
        std::cin >> in;
    };
    return in == "true" ? true : false;
}

uint16_t inputBrightness() {
    uint16_t in = -1;
    std::cout << "Enter brightness (0-100):\n";
    while(in > 100) {
        std::cin >> in;
    };
    return in;
}