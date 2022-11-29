#include "datarefs.h"
#include <cstring>

int pttHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon);
XPLMCommandRef pttCommand;
bool ptt;
XPLMDataRef drefLatitude;
XPLMDataRef drefLongitude;
XPLMDataRef drefHeight;

XPLMDataRef drefCom1Frequency;
XPLMDataRef drefCom1Power;
XPLMDataRef drefCom1Listening;
XPLMDataRef drefCom1Volume;
XPLMDataRef drefCom2Frequency;
XPLMDataRef drefCom2Power;
XPLMDataRef drefCom2Listening;
XPLMDataRef drefCom2Volume;

XPLMDataRef drefComSelection;

void findDatarefs()
{
    pttCommand = XPLMCreateCommand("fgcom-mumble/ptt", "Push-to-talk");
    XPLMRegisterCommandHandler(pttCommand, pttHandler, 1, (void *)0);

    drefLatitude = XPLMFindDataRef("sim/flightmodel/position/latitude");
    drefLongitude = XPLMFindDataRef("sim/flightmodel/position/longitude");
    drefHeight = XPLMFindDataRef("sim/flightmodel/position/y_agl");
    drefCom1Frequency = XPLMFindDataRef("sim/cockpit2/radios/actuators/com1_frequency_hz_833");
    drefCom1Power = XPLMFindDataRef("sim/cockpit2/radios/actuators/com1_power");
    drefCom1Listening = XPLMFindDataRef("sim/cockpit2/radios/actuators/audio_selection_com1");
    drefCom1Volume = XPLMFindDataRef("sim/cockpit2/radios/actuators/audio_volume_com1");
    drefCom2Frequency = XPLMFindDataRef("sim/cockpit2/radios/actuators/com2_frequency_hz_833");
    drefCom2Power = XPLMFindDataRef("sim/cockpit2/radios/actuators/com2_power");
    drefCom2Listening = XPLMFindDataRef("sim/cockpit2/radios/actuators/audio_selection_com2");
    drefCom2Volume = XPLMFindDataRef("sim/cockpit2/radios/actuators/audio_volume_com2");
    drefComSelection = XPLMFindDataRef("sim/cockpit2/radios/actuators/audio_com_selection");
}

int pttHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon)
{
    switch (inPhase) {
    case 0:
        ptt = true;
        break;
    case 2:
        ptt = false;
        break;
    }
    return 0;
}
