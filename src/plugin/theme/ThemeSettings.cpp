#include "ThemeSettings.h"

namespace UKControllerPlugin::Theme {

    ThemeSettings::ThemeSettings(EuroScope::UserSetting& userSettings_) : userSettings(userSettings_)
    {
    }

    auto ThemeSettings::Palette() const -> std::string
    {
        return userSettings.GetStringEntry(PALETTE_KEY, Palette::DEFAULT);
    }

    void ThemeSettings::SetPalette(std::string id)
    {
        userSettings.SetStringEntry(PALETTE_KEY, std::move(id));
    }

} // namespace UKControllerPlugin::Theme
