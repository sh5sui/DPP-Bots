#include "Links.h"

void register_Links(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("links", "Leagues Links", bot.me.id)
    );

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "links") {
            event.reply("League is still under development so links will be established soon!");

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel,
                    "Links command was executed by <@" +
                    std::to_string(event.command.usr.id) +
                    ">")
            );
        }
        });
}
