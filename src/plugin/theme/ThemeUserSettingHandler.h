#pragma once

#include "euroscope/UserSettingAwareInterface.h"

namespace UKControllerPlugin::Theme {

    /*
        Bootstraps the theming module.
    */
    class ThemeUserSettingHandler : public Euroscope::UserSettingAwareInterface
    {
        public:
        ThemeUserSettingHandler(std::shared_ptr<ThemeSettings> settings);
        void UserSettingsUpdated(Euroscope::UserSetting& userSettings) override;

        private:
        std::shared_ptr<ThemeSettings> settings;
    };

} // namespace UKControllerPlugin::Theme
