#include "pch/pch.h"
#include "hold/HoldingAircraft.h"

using UKControllerPlugin::Hold::HoldingAircraft;
using ::testing::Test;

namespace UKControllerPluginTest {
    namespace Hold {

        class HoldingAircraftTest : public Test
        {
            public:
                HoldingAircraft baseAircraft = {
                    "BAW123",
                    7000,
                    8000,
                    350,
                    std::chrono::system_clock::now()
                };
        };

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsTrueIdentical)
        {
            EXPECT_TRUE(baseAircraft == baseAircraft);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsTrueDifferentClearedLevel)
        {
            HoldingAircraft compare = {
                "BAW123",
                9000,
                8000,
                350,
                std::chrono::system_clock::now()
            };
            EXPECT_TRUE(baseAircraft == compare);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsTrueDifferentReportedLevel)
        {
            HoldingAircraft compare = {
                "BAW123",
                7000,
                9000,
                350,
                std::chrono::system_clock::now()
            };
            EXPECT_TRUE(baseAircraft == compare);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsTrueDifferentVerticalSpeed)
        {
            HoldingAircraft compare = {
                "BAW123",
                7000,
                8000,
                400,
                std::chrono::system_clock::now()
            };
            EXPECT_TRUE(baseAircraft == compare);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsTrueDifferentEntryTime)
        {
            HoldingAircraft compare = {
                "BAW123",
                7000,
                8000,
                350,
                std::chrono::system_clock::now() - std::chrono::seconds(25)
            };
            EXPECT_TRUE(baseAircraft == compare);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStructReturnsFalseDifferentCallsign)
        {
            HoldingAircraft compare = {
                "BAW124",
                7000,
                8000,
                350,
                std::chrono::system_clock::now()
            };
            EXPECT_FALSE(baseAircraft == compare);
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStringReturnsFalseDifferentCallsign)
        {
            EXPECT_FALSE(baseAircraft == "BAW124");
        }

        TEST_F(HoldingAircraftTest, EqualityOperatorStringReturnsTrueSameCallsign)
        {
            EXPECT_TRUE(baseAircraft == "BAW123");
        }
    }  // namespace Hold
}  // namespace UKControllerPluginTest
