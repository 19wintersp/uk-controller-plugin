#include "approach/ApproachSequencerDisplay.h"

using UKControllerPlugin::Approach::ApproachSequencerDisplay;

namespace UKControllerPluginTest::Approach {
    class ApproachSequencerDisplayTest : public testing::Test
    {
        public:
        ApproachSequencerDisplayTest() : display(55)
        {
        }

        testing::NiceMock<Euroscope::MockEuroscopeRadarScreenLoopbackInterface> radarScreen;
        ApproachSequencerDisplay display;
    };

    TEST_F(ApproachSequencerDisplayTest, ItTogglesContentCollapsing)
    {
        EXPECT_FALSE(display.ContentCollapsed());
        display.LeftClick(radarScreen, 1, "collapseButton", {}, {});
        EXPECT_TRUE(display.ContentCollapsed());
        display.LeftClick(radarScreen, 1, "collapseButton", {}, {});
        EXPECT_FALSE(display.ContentCollapsed());
    }
} // namespace UKControllerPluginTest::Approach
