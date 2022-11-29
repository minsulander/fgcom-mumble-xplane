#ifndef __DATAREFS_H__
#define __DATAREFS_H__

#include "XPLMDataAccess.h"
#include "XPLMPlugin.h"
#include "XPLMProcessing.h"
#include "XPLMUtilities.h"

extern XPLMCommandRef pttCommand;
extern bool ptt;
extern XPLMDataRef drefLatitude;
extern XPLMDataRef drefLongitude;
extern XPLMDataRef drefHeight; // meters

extern XPLMDataRef drefCom1Frequency;
extern XPLMDataRef drefCom1Power;
extern XPLMDataRef drefCom1Listening;
extern XPLMDataRef drefCom1Volume;
extern XPLMDataRef drefCom2Frequency;
extern XPLMDataRef drefCom2Power;
extern XPLMDataRef drefCom2Listening;
extern XPLMDataRef drefCom2Volume;

extern XPLMDataRef drefComSelection;

extern void findDatarefs();

#endif
