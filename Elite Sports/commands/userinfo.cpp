#include "Userinfo.h"

void register_Userinfo(dpp::cluster& bot) {
            dpp::slashcommand userinfo_command("userinfo", "Get user info on a person", bot.me.id);
            userinfo_command
                .add_option(dpp::command_option(dpp::co_user, "user", "User you want the information of", true));
            bot.global_command_create(userinfo_command);

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "userinfo") {
            dpp::snowflake target_id = std::get<dpp::snowflake>(event.get_parameter("user"));
            dpp::user target_user = event.command.get_resolved_user(target_id);

            std::string mention = "<@" + std::to_string(target_id) + ">";
            std::string user = target_user.get_mention();

            dpp::embed embed = dpp::embed()
                .set_color(dpp::colors::orchid)
                .set_author("Author: " + event.command.usr.username, "", "")
                .set_description("User info for " + mention + ", Requested by <@" + std::to_string(event.command.usr.id) + ">")
                .set_thumbnail(target_user.get_avatar_url())
                .add_field("Profile URL", target_user.get_url(), true)
                .add_field("Bot", target_user.is_bot() ? "True" : "False", false)
                .add_field("Has Nitro", target_user.has_nitro_full() or target_user.has_nitro_basic() ? "True" : "False", false);

            event.reply(
                dpp::message().add_embed(embed)
            );
        }
    });
}