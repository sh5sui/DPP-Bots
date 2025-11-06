#include "Bot.h"
#include "commands/links.h"
#include "commands/commands.h"
#include "commands/Userinfo.h"
#include "commands/Suggest.h"
#include "commands/Friendly.h"
#include "commands/freeagent.h"

Bot::Bot(const std::string& token) : bot(token, dpp::i_default_intents) {
    bot.on_log(dpp::utility::cout_logger());
    bot.on_ready([this](const dpp::ready_t& event){
        std::cout << "Bot is online\n";
    });
}

void Bot::start() {
    load_commands();
    bot.start(dpp::st_wait);
}

void Bot::load_commands() {
    register_Links(bot);
    register_Commands(bot);
    register_Userinfo(bot);
    register_Suggest(bot);
    register_Friendly(bot);
    register_Freeagent(bot);
}
