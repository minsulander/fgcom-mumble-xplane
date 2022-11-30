#include "udpsender.h"

// #include <asio/io_context.hpp>
// using asio::ip::udp;

#include "PracticalSocket.h"
#include "XPLMUtilities.h"
#include <sstream>

#include "datarefs.h"

UDPSender::UDPSender()
{
    sockpp::socket_initializer sockinit;
}

void UDPSender::send()
{
    int comsel = XPLMGetDatai(drefComSelection);
    std::ostringstream ss;
    ss << "CALLSIGN=XPL001,LAT=" << XPLMGetDatad(drefLatitude)
       << ",LON=" << XPLMGetDatad(drefLongitude) << ",HGT=" << (XPLMGetDataf(drefHeight) * 3.28084)
       << ",COM1_PTT=" << ((ptt && comsel == 6) ? 1 : 0)
       << ",COM1_FRQ=" << (XPLMGetDatai(drefCom1Frequency) / 1000.0)
       << ",COM1_VOL=" << XPLMGetDataf(drefCom1Volume) << ",COM1_PWR=10.0,COM1_SQC=0.1,COM1_CWKHZ=8.33"
       << ",COM1_PBT=" << (XPLMGetDatai(drefCom1Power) && XPLMGetDatai(drefCom1Listening))
       << ",COM2_PTT=" << ((ptt && comsel == 7) ? 1 : 0)
       << ",COM2_FRQ=" << (XPLMGetDatai(drefCom2Frequency) / 1000.0)
       << ",COM2_VOL=" << XPLMGetDataf(drefCom2Volume) << ",COM2_PWR=10.0,COM2_SQC=0.1,COM2_CWKHZ=8.33"
       << ",COM2_PBT=" << (XPLMGetDatai(drefCom2Power) && XPLMGetDatai(drefCom2Listening))
       << ",DEBUG_SIGQLY=-1.0,AUDIO_FX_RADIO=1,AUDIO_HEAR_ALL=0"
       << "\n";
    auto str = ss.str();
    // XPLMDebugString(str.c_str());
    socket.send_to(str, sockpp::inet_address("localhost", 16661));
}