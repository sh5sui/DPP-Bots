#include "Commands.h"

void register_Commands(dpp::cluster& bot) {
    bot.global_command_create(
        dpp::slashcommand("commands", "Shows all available commands", bot.me.id)
    );

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "commands") {
                        dpp::embed embed = dpp::embed()
                .set_color(dpp::colors::sti_blue)
                .set_author("Commands", "", "")
                .set_description("All available commands on this bot")
                .set_thumbnail("https://cdn.discordapp.com/attachments/1426889463925051573/1432361136015151134/ES-1.png?ex=6900c5c2&is=68ff7442&hm=198dfca273a4fcaec68a474fce6119b9a9d97411667bbda7552c7b3308c0c389&")
                .add_field("Commands", "Shows this embed with all available commands.")
                .add_field("Links", "Tells you all of the links such as to the discord server, roblox game, Etc.")
                .add_field("Suggest", "Tells you where to make suggests or bug reports for the bot.")
                .add_field("Testlogs", "Tests the logging of the bot to the logs channel dedicated inside of the server (Requires permissions)")
                .add_field("Friendly", "Sends a request for a friendly inside of the friendlies channel")
                .add_field("FreeAgent", "Sends a free agency request inside of the free agency channel")
                .set_image("")
                .set_timestamp(time(0));
        }
    });
}
