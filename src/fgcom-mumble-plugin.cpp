#include "XPLMPlugin.h"
#include <cstring>

PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc) {
    // Plugin details
	strcpy(outName, "FGCom-mumble");
	strcpy(outSig, "com.insulander.martin.fgcom-mumble-xplane");
	strcpy(outDesc, "FGCom-mumble X-Plane Plugin");

    // You probably want this on
	XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);

	return 1;
}

PLUGIN_API void	XPluginStop(void) {
}

PLUGIN_API void XPluginDisable(void) {
}

PLUGIN_API int XPluginEnable(void) {
	return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID, intptr_t inMessage, void * inParam) {
}
