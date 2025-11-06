#include "Friendly.h"

void register_Friendly(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("friendly", "Request a friendly", bot.me.id)
    );

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "friendly") {
                        event.reply("Friendly request was sent in <#1426889475644194816>");

            dpp::snowflake target_channel = 1426889475644194816;
            bot.message_create(
                dpp::message(target_channel, "<@" + std::to_string(event.command.usr.id) + "> Is looking for a friendly. ||<@1426889327723548755>||")
            );

            dpp::snowflake target_channel1 = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel1, "<@" + std::to_string(event.command.usr.id) + "> Has executed the *friendly* command")
            );
        }
    });
}