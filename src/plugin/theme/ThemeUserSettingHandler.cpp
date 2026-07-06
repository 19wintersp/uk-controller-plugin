#include "ThemeUserSettingHandler.h"

namespace UKControllerPlugin::Theme {

    ThemeUserSettingHandler::ThemeUserSettingHandler(std::shared_ptr<ThemeSettings> settings_) : settings(settings_)
    {
        UserSettingsUpdated();
    }

    void ThemeUserSettingHandler::UserSettingsUpdated(Euroscope::UserSetting&)
    {
        auto palette = Palette::GetPalette(settings.Palette().c_str());
        ThemeManager::Instance().ApplyPalette(palette);
    }

} // namespace UKControllerPlugin::Theme
