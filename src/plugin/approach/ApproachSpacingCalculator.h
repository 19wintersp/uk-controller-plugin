#pragma once

namespace UKControllerPlugin {
    namespace Airfield {
        class AirfieldCollection;
    } // namespace Airfield
    namespace Wake {
        class WakeCategoryMapperCollection;
    } // namespace Wake
} // namespace UKControllerPlugin

namespace UKControllerPlugin::Approach {
    class ApproachSequencedAircraft;

    /**
     * Calculates the required distance between an aircraft and the previous aircraft.
     */
    class ApproachSpacingCalculator
    {
        public:
        ApproachSpacingCalculator(
            const Airfield::AirfieldCollection& airfields, const Wake::WakeCategoryMapperCollection& wakeMappers);
        [[nodiscard]] auto Calculate(const std::string& airfield, const ApproachSequencedAircraft& aircraft) const
            -> double;
        [[nodiscard]] static auto NoSpacing() -> double;

        private:
        inline static const double NO_SPACING_DETECTED = -1.0;

        // All the airfields
        const Airfield::AirfieldCollection& airfields;

        // The wake schemes
        const Wake::WakeCategoryMapperCollection& wakeMappers;
    };
} // namespace UKControllerPlugin::Approach
