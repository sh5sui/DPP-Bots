#include "freeagent.h"

void register_Freeagent(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("freeagent", "Send a free agent request", bot.me.id)
    );

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "freeagent") {
                        event.reply("Sent free agency to the free agency channel!");

            dpp::snowflake target_channel = 1426889478567493724;
            bot.message_create(
                dpp::message(target_channel, "<@" + std::to_string(event.command.usr.id) + "> " + "Is a free agent. DM him to trial or sign him!"));

            dpp::snowflake target_channel1 = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel1, "Free agency command was executed by <@" + std::to_string(event.command.usr.id) + ">")
            );
        }
    });
}