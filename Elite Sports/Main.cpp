#include <iostream>
#include <cstdlib>
#include "Bot.h"
#define _CRT_SECURE_NO_WARNINGS

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
