#pragma once

namespace UKControllerPlugin::Theme {

    /*
        Bootstraps the theming module.
    */
    class ThemeModule
    {
        public:
        static void BootstrapPlugin(Bootstrap::PersistenceContainer& container);
    };

} // namespace UKControllerPlugin::Theme
