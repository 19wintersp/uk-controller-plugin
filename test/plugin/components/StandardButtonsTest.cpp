#include "components/StandardButtons.h"

using testing::_;
using UKControllerPlugin::Components::CloseButton;
using UKControllerPlugin::Components::CollapseButton;

namespace UKControllerPluginTest::Components {

    class StandardButtonsTest : public testing::Test
    {
        public:
        StandardButtonsTest() = default;
        testing::NiceMock<Windows::MockGraphicsInterface> mockGraphics;
    };

    TEST_F(StandardButtonsTest, CloseButtonThemedDoesNotCrash)
    {
        auto button = CloseButton();
        EXPECT_NE(nullptr, button.target_type().name());
    }

    TEST_F(StandardButtonsTest, CollapseButtonThemedDoesNotCrash)
    {
        auto button = CollapseButton([]() { return false; });
        EXPECT_NE(nullptr, button.target_type().name());
    }

    TEST_F(StandardButtonsTest, CloseButtonWithColorDoesNotCrash)
    {
        auto button = CloseButton(Gdiplus::Color(255, 0, 0));
        EXPECT_NE(nullptr, button.target_type().name());
    }

    TEST_F(StandardButtonsTest, CollapseButtonWithColorDoesNotCrash)
    {
        auto button = CollapseButton(Gdiplus::Color(255, 0, 0), []() { return false; });
        EXPECT_NE(nullptr, button.target_type().name());
    }
} // namespace UKControllerPluginTest::Components
