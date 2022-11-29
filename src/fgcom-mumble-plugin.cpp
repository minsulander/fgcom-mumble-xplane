#include "XPLMPlugin.h"
#include "XPLMProcessing.h"
#include "XPLMUtilities.h"
#include <cstring>

#include "datarefs.h"
#include "udpsender.h"

// Forward declaration
float sendLoop(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void *inRefcon);

UDPSender *sender;
bool initialized;

PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc)
{
    // Plugin details
    strcpy(outName, "FGCom-mumble");
    strcpy(outSig, "com.insulander.martin.fgcom-mumble-xplane");
    strcpy(outDesc, "FGCom-mumble X-Plane Plugin");

    // You probably want this on
    XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);

    findDatarefs();
    sender = new UDPSender();

    XPLMRegisterFlightLoopCallback(sendLoop, 0.1f, NULL);

    return 1;
}

PLUGIN_API void XPluginStop(void)
{
}

PLUGIN_API void XPluginDisable(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID, intptr_t inMessage, void *inParam)
{
}

float sendLoop(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void *inRefcon)
{
    sender->send();
    return 0.1f;
}
