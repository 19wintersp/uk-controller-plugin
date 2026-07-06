#pragma once

#include "theme/PaletteKey.h"

namespace UKControllerPlugin::Theme {

    /*
        Manager for user-customisable graphical preferences.
    */
    class ThemeManager
    {
        public:
        static auto Instance() -> ThemeManager&;
        static void UnsetInstance();

        // Shortcut methods for caller brevity
        [[nodiscard]] static auto Brush(PaletteKey key) const -> const Gdiplus::SolidBrush&;
        [[nodiscard]] static auto Pen(PaletteKey key) const -> const Gdiplus::Pen&;

        [[nodiscard]] auto GetBrush(PaletteKey key) const -> const Gdiplus::SolidBrush&;
        [[nodiscard]] auto GetPen(PaletteKey key) const -> const Gdiplus::Pen&;

        void ApplyPalette(const Palette& palette);

        private:
        ThemeManager();

        inline static std::unique_ptr<ThemeManager> instance;

        std::unique_ptr<Gdiplus::SolidBrush> brush_cache[PALETTE_KEY_COUNT];
        std::unique_ptr<Gdiplus::Pen> pen_cache[PALETTE_KEY_COUNT];
    };

} // namespace UKControllerPlugin::Theme
