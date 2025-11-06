#include "Suggest.h"

void register_Suggest(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("suggest", "Suggest improvements or report bugs", bot.me.id)
    );

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "suggest") {
            event.reply("You can suggest additions to the bot by dming <@610825208999182336> or opening a ticket. You can also report bugs the same way.");

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(
                    target_channel,
                    "Suggest command was executed by <@" +
                    std::to_string(event.command.usr.id) +
                    ">"
                )
            );
        }
        });
}
