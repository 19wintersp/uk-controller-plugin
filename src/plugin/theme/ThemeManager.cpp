#include "ThemeManager.h"

namespace UKControllerPlugin::Theme {

    auto ThemeManager::Instance() -> ThemeManager& {
        if (!instance) {
            instance = std::make_unique<ThemeManager>();
        }

        return *instance;
    }

    void ThemeManager::UnsetInstance() {
        instance = nullptr;
    }

    auto ThemeManager::Brush(PaletteKey key) const -> const Gdiplus::SolidBrush& {
        return Instance().GetBrush(key);
    }

    auto ThemeManager::Pen(PaletteKey key) const -> const Gdiplus::Pen& {
        return Instance().GetPen(key);
    }

    auto ThemeManager::GetBrush(PaletteKey key) const -> const Gdiplus::SolidBrush& {
        return *brush_cache[static_cast<std::size_t>(key)];
    }

    auto ThemeManager::GetPen(PaletteKey key) const -> const Gdiplus::Pen& {
        return *pen_cache[static_cast<std::size_t>(key)];
    }

    void ThemeManager::ApplyPalette(const Palette &palette) {
        for (std::size_t key = 0; key < PALETTE_KEY_COUNT; ++key) {
            auto entry = palette.GetEntry(static_cast<PaletteKey>(key));
            auto colour = Gdiplus::Color(entry.value);
            brush_cache[key] = std::make_unique<Gdiplus::SolidBrush>(colour);
            pen_cache[key] = std::make_unique<Gdiplus::Pen>(colour);
        }
    }

    ThemeManager::ThemeManager() {
        // Apply default palette
        ApplyPalette(Palette::GetPalette(""));
    }

} // namespace UKControllerPlugin::Theme
