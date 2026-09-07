#pragma once

#include "theme/Palette.h"
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
        [[nodiscard]] static auto Colour(PaletteKey key) -> Gdiplus::Color;
        [[nodiscard]] static auto Brush(PaletteKey key) -> const Gdiplus::SolidBrush&;
        [[nodiscard]] static auto Pen(PaletteKey key) -> const Gdiplus::Pen&;

        [[nodiscard]] auto GetColour(PaletteKey key) const -> Gdiplus::Color;
        [[nodiscard]] auto GetBrush(PaletteKey key) const -> const Gdiplus::SolidBrush&;
        [[nodiscard]] auto GetPen(PaletteKey key) const -> const Gdiplus::Pen&;

        void ApplyPalette(const Palette* palette);

        private:
        ThemeManager();

        inline static std::unique_ptr<ThemeManager> instance;

        Gdiplus::Color colours[PALETTE_KEY_COUNT];
        std::unique_ptr<Gdiplus::SolidBrush> brushes[PALETTE_KEY_COUNT];
        std::unique_ptr<Gdiplus::Pen> pens[PALETTE_KEY_COUNT];
    };

} // namespace UKControllerPlugin::Theme
