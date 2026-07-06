#include "Palette.h"

namespace UKControllerPlugin::Theme {

    auto GetEntry(PaletteKey key) const -> PaletteEntry
    {
        return entries[static_cast<std::size_t>(key)];
    }

    auto GetId() const -> const char * {
        return id;
    }

    auto GetName() const -> const char * {
        return name;
    }

    constexpr Palette::Palette(
        const char* id_, const char* name_, std::initializer_list<std::pair<PaletteKey, PaletteEntry>> entries_)
        : id(id_), name(name_)
    {
        for (const auto [key, entry] : entries_)
            entries[static_cast<std::size_t>(key)] = entry;
    }

    constexpr Palette::Palette(
        const char* id,
        const char* name,
        const Palette& base,
        std::initializer_list<std::pair<PaletteKey, PaletteEntry>> overrides)
        : id(id_), name(name_)
    {
        for (std::size_t i = 0; i < PALETTE_KEY_COUNT; ++i)
            entries[i] = base.entries[i];
        for (const auto [key, entry] : overrides)
            entries[static_cast<std::size_t>(key)] = entry;
    }

    // clang-format off
    constexpr static const Palette
        BASE_PALETTE(
            Palette::DEFAULT,
            "Classic",
            {{PaletteKey::Background,            "#3a393a"},
             {PaletteKey::Border,                "#d7d7d7"},
             {PaletteKey::Header,                "#82329a"},
             {PaletteKey::HeaderHighlight,       "#ff99ff"},
             {PaletteKey::Text,                  "#e3e3e3"},
             {PaletteKey::TextHighlight,         "#ffff00"},
             {PaletteKey::AircraftText,          "#07ed07"},
             {PaletteKey::AircraftTextHighlight, "#f6b504"},
             {PaletteKey::TimerGreen,            "#00ff00"},
             {PaletteKey::TimerYellow,           "#ffff00"},
             {PaletteKey::TimerRed,              "#ff0000"}}),
        NODE_PALETTE(
            "node",
            "NODE",
            {{PaletteKey::Background,            "#000000"},
             {PaletteKey::Border,                "#ffffff"},
             {PaletteKey::Header,                "#a06f70"},
             {PaletteKey::HeaderHighlight,       "#ff6432"},
             {PaletteKey::Text,                  "#ffffff"},
             {PaletteKey::TextHighlight,         "#e8a300"},
             {PaletteKey::AircraftText,          "#68dd45"},
             {PaletteKey::AircraftTextHighlight, "#e8a300"},
             {PaletteKey::TimerGreen,            "#68dd45"},
             {PaletteKey::TimerYellow,           "#e8a300"},
             {PaletteKey::TimerRed,              "#ff6432"}}),
        NERC_PALETTE(
            "nerc",
            "NERC",
            {{PaletteKey::Background,            "#969696"},
             {PaletteKey::Border,                "#535353"},
             {PaletteKey::Header,                "#878787"},
             {PaletteKey::HeaderHighlight,       "#ffffff"},
             {PaletteKey::Text,                  "#000000"},
             {PaletteKey::TextHighlight,         "#ffffff"},
             {PaletteKey::AircraftText,          "#000000"},
             {PaletteKey::AircraftTextHighlight, "#ffffff"},
             {PaletteKey::TimerGreen,            "#b4ff7d"},
             {PaletteKey::TimerYellow,           "#ffd800"},
             {PaletteKey::TimerRed,              "#c00000"}}),
        NOVA_PALETTE(
            "nova",
            "NOVA",
            NERC_PALETTE,
            {{PaletteKey::Background,            "#b4b4b4"},
             {PaletteKey::Header,                "#008cc8"},
             {PaletteKey::TimerGreen,            "#ffffff"}}),
        ITEC_PALETTE(
            "itec",
            "iTEC",
            NERC_PALETTE,
            {{PaletteKey::Background,            "#c3c3b9"},
             {PaletteKey::Border,                "#000000"},
             {PaletteKey::Header,                "#d6d896"},
             {PaletteKey::TextHighlight,         "#0000ff"},
             {PaletteKey::AircraftTextHighlight, "#0000ff"},
             {PaletteKey::TimerGreen,            "#0000ff"}});
    // clang-format on

    const std::vector<const Palette&> Palette::PALETTES = {
        BASE_PALETTE, NODE_PALETTE, NERC_PALETTE, NOVA_PALETTE, ITEC_PALETTE};

    static auto GetPalettes() const -> const std::vector<const Palette&>&
    {
        return PALETTES;
    }

    static auto GetPalette(const char* id) const -> const Palette&
    {
        for (const Palette& palette : PALETTES)
            if (!std::strcmp(palette.id, id))
                return palette;

        return BASE_PALETTE;
    }

} // namespace UKControllerPlugin::Theme
