#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "Bot.h"

int main() {
    const char* token = std::getenv("Token");
    if (!token) {
        std::cerr << "Error: Token not set" << std::endl;
        return 1;
    }

    Bot bot(token);
    bot.start();

    return 0;
}
