#include <dpp/dpp.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>


// TODO: Add logs to every command
int main() {
    char* token = nullptr;
    size_t len = 0;
    errno_t err = _dupenv_s(&token, &len, "DISCORD_TOKEN");
    if (err != 0 || token == nullptr) {
        std::cerr << "Error: DISCORD_TOKEN not set\n";
        return 1;
    }

    dpp::cluster bot(token, dpp::i_default_intents | dpp::i_message_content);

    free(token);

    bot.on_log(dpp::utility::cout_logger());

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
                .add_field("Ban", "Bans a member (Requires permissions)")
                .add_field("Unban", "Clears a members ban (Requires premissions)")
                .add_field("Kick", "Kicks a user (Requires permissions)")
                .add_field("Testlogs", "Tests the logging of the bot to the logs channel dedicated inside of the server (Requires permissions)")
                .add_field("Friendly", "Sends a request for a friendly inside of the friendlies channel")
                .add_field("FreeAgent", "Sends a free agency request inside of the free agency channel")
                .set_image("")
                .set_timestamp(time(0));

            dpp::message msg(event.command.channel_id, embed);
            event.reply(msg);

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel, "*Commands* was executed by <@" + std::to_string(event.command.usr.id) + ">")
            );
        }
        else if (event.command.get_command_name() == "links") {
            event.reply("League is still under development so links will be established soon!");

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel, "Links command was executed by <@" + std::to_string(event.command.usr.id) + ">")
            );
        }
        else if (event.command.get_command_name() == "friendly") {
            event.reply("Friendly request was sent in <#1426889475644194816>");

            dpp::snowflake target_channel = 1426889475644194816;
            bot.message_create(
                dpp::message(target_channel, "<@" + std::to_string(event.command.usr.id) + "> " "Is looking for a friendly. ||<@1426889327723548755>||")

                dpp::snowflake target_channel1 = 1432683879071875204;
                bot.message_create(
                    dpp::message(target_channel1, "<@" + std::to_string(event.command.usr.id) + ">" " Has executed the *friendly* command")
                )
            );
        }
        else if (event.command.get_command_name() == "suggest") {
            event.reply("You can suggest additions to the bot by dming <@610825208999182336> or opening a ticket. You can also report bugs the same way.");

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel, "Suggest command was executed by <@" + std::to_string(event.command.usr.id) + ">")
            );
        }
        else if (event.command.get_command_name() == "freeagent") {
            event.reply("Sent free agency to the free agency channel!");

            dpp::snowflake target_channel = 1426889478567493724;
            bot.message_create(
                dpp::message(target_channel, "<@" + std::to_string(event.command.usr.id) + "> " + "Is a free agent. DM him to trial or sign him!"));

            dpp::snowflake target_channel1 = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel1, "Free agency command was executed by <@" + std::to_string(event.command.usr.id) + ">")
            );

        }
        // TODO: Add function to this command for sending contracts
        else if (event.command.get_command_name() == "sign") {

        }

        // TODO: Add function to this command to release people from teams
        else if (event.command.get_command_name() == "release") {

        }
        // TODO: Add function to this command to appoint someone to be a team manager
        else if (event.command.get_command_name() == "manager") {

        }
        else if (event.command.get_command_name() == "testlogs") {
            event.reply("Logs have been successfully sent.");

            dpp::snowflake target_channel = 1432683879071875204;
            bot.message_create(
                dpp::message(target_channel, "Command was executed successfully.")
            );
        }
        // TODO: Add function to this to display all members of the "manager" role
        });

    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        try {
            std::string content = event.msg.content;
            std::transform(content.begin(), content.end(), content.begin(), ::tolower);

            if (content.find("nigger") != std::string::npos ||
                content.find("faggot") != std::string::npos ||
                content.find("discord.gg/") != std::string::npos ||
                content.find(".gg/") != std::string::npos) {

                bot.message_delete(event.msg.id, event.msg.channel_id, [&bot, event](const dpp::confirmation_callback_t& callback) {
                    if (callback.is_error()) {
                        std::cout << "Failed to delete message: " << callback.http_info.body << std::endl;
                        return;
                    }

                    event.reply("These messages could include hate speech or link advertising. If your message falls under this category, moderators have full permission to take action against you to the extent they see fit. Please refrain from this in the future.", true);
                    });
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error in message_create event: " << e.what() << std::endl;
        }
        });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("commands", "All available commands.", bot.me.id));
            bot.global_command_create(dpp::slashcommand("links", "Leagues Links", bot.me.id));
            bot.global_command_create(dpp::slashcommand("suggest", "Give a suggestion!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("testlogs", "Test the sending of the bots logs", bot.me.id));
            bot.global_command_create(dpp::slashcommand("friendly", "Request a friendly in the friendlies channel", bot.me.id));

            dpp::slashcommand freeagent_command("Free Agency", "Send a message in free agency", bot.me.id);
            freeagent_command
                .add_option(dpp::command_option(dpp::co_string, "Region", "What region your in", true))
                .add_option(dpp::command_option(dpp::co_string, "Position", "What position you play", true));
            bot.global_command_create(freeagent_command);
        }
        });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_game, "Genoside"));
        });

    bot.start(dpp::st_wait);
    return 0;
}
