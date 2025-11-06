#pragma once
#include <dpp/dpp.h>

class Bot {
public:
    dpp::cluster bot;

    Bot(const std::string& token);

    void start();
private:
    void load_commands();
};
