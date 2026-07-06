#pragma once

#include "theme/PaletteEntry.h"
#include "theme/PaletteKey.h"

namespace UKControllerPlugin::Theme {

    /*
        Defines the colours used by a particular UI palette.
    */
    class Palette
    {
        public:
        [[nodiscard]] auto GetEntry(PaletteKey key) const -> PaletteEntry;
        [[nodiscard]] auto GetId() const -> const char *;
        [[nodiscard]] auto GetName() const -> const char *;

        [[nodiscard]] static auto GetPalettes() const -> const std::vector<const Palette&>&;
        [[nodiscard]] static auto GetPalette(const char* id) const -> const Palette&;

        constexpr Palette(
            const char* id, const char* name, std::initializer_list<std::pair<PaletteKey, PaletteEntry>> entries);
        constexpr Palette(
            const char* id,
            const char* name,
            const Palette& base,
            std::initializer_list<std::pair<PaletteKey, PaletteEntry>> overrides);

        static const std::string DEFAULT = "default";

        private:
        const char *id, *name;
        PaletteEntry entries[PALETTE_KEY_COUNT];

        static const std::vector<const Palette&> PALETTES;
    };

} // namespace UKControllerPlugin::Theme
