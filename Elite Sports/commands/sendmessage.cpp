#include "sendmessage.h"

void register_Sendmessage(dpp::cluster& bot) {
        dpp::slashcommand sendmessage_command("sendmessage", "Sends a message in a certain channel", bot.me.id);
        sendmessage_command
            .add_option(dpp::command_option(dpp::co_string, "message", "Message to send in the channel", true))
            .add_option(dpp::command_option(dpp::co_string, "channelid", "Channel ID to send the message to", true));
        bot.global_command_create(sendmessage_command);

        bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
            if (event.command.get_command_name() == "sendmessage") {
                            std::string message_text = std::get<std::string>(event.get_parameter("message"));

            std::string id_str = std::get<std::string>(event.get_parameter("id"));

            dpp::snowflake target_channel = std::stoull(id_str);

            if (event.command.usr.id != 610825208999182336) {
                event.reply("You cannot run this command.");
            }
            else {
                bot.message_create(dpp::message(target_channel, message_text));
            }}
    });
}