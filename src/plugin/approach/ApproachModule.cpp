#include "ApproachModule.h"
#include "ApproachSpacingRingRenderer.h"
#include "bootstrap/PersistenceContainer.h"
#include "plugin/UKPlugin.h"
#include "radarscreen/RadarRenderableCollection.h"

namespace UKControllerPlugin::Approach {

    void ApproachModule::BootstrapPlugin(Bootstrap::PersistenceContainer& container)
    {
    }

    void ApproachModule::BootstrapRadarScreen(
        const Bootstrap::PersistenceContainer& container,
        RadarScreen::RadarRenderableCollection& radarRenderables,
        RadarScreen::ConfigurableDisplayCollection& configurables,
        Euroscope::AsrEventHandlerCollection& asrHandlers)
    {
        radarRenderables.RegisterRenderer(
            radarRenderables.ReserveRendererIdentifier(),
            std::make_shared<ApproachSpacingRingRenderer>(*container.plugin),
            radarRenderables.beforeTags);
    }
} // namespace UKControllerPlugin::Approach
