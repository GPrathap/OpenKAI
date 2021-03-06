/*
 * Module.h
 *
 *  Created on: Nov 22, 2016
 *      Author: root
 */

#ifndef OPENKAI_SRC_CONFIG_MODULE_H_
#define OPENKAI_SRC_CONFIG_MODULE_H_

#include "../Base/common.h"
#include "../Base/BASE.h"
#include "../Script/Kiss.h"
#include "switch.h"

#include "../Automaton/_Automaton.h"

#include "../Detector/_AprilTags.h"
#include "../Detector/_Bullseye.h"

#include "../IO/SerialPort.h"

#include "../include/apriltags-cpp/TagDetector.h"

#include "../Navigation/_GPS.h"
#include "../Navigation/_Path.h"

#include "../Autopilot/Action/ActionBase.h"
#include "../Autopilot/Action/HM/HM_base.h"
#include "../Autopilot/Action/RC/RC_base.h"
#include "../Autopilot/Action/RC/RC_visualFollow.h"
#include "../Autopilot/_AutoPilot.h"
#include "../Autopilot/Action/HM/HM_grass.h"
#include "../Autopilot/Action/APcopter/APcopter_base.h"
#include "../Autopilot/Action/APcopter/APcopter_landing.h"
#include "../Autopilot/Action/AProver/AProver_base.h"
#include "../Autopilot/Action/AProver/AProver_follow.h"

#include "../IO/File.h"

#include "../Network/_server.h"
#include "../Network/_socket.h"

#include "../DNN/_ImageNet.h"
#include "../DNN/_MatrixNet.h"
#include "../DNN/_DetectNet.h"
#include "../Odometry/_DNNodometry.h"

#include "../Protocol/_Canbus.h"
#include "../Protocol/_Mavlink.h"
#include "../Protocol/_RC.h"

#include "../Sensor/_Obstacle.h"
#include "../Sensor/_Lightware_SF40_sender.h"
#include "../Sensor/_Lightware_SF40.h"
#include "../Sensor/_LeddarVu.h"
#include "../Tracker/_ROITracker.h"

#include "../UI/UI.h"
#include "../UI/Window.h"

#include "../Vision/Frame.h"
#include "../Vision/_Camera.h"
#include "../Vision/_VisionBase.h"
#include "../Vision/_ZED.h"
#include "../Vision/FrameGroup.h"
#include "../Vision/_Flow.h"

#ifdef USE_CASCADE
#include "../AI/_Cascade.h"
#endif
#ifdef USE_SSD
#include "../AI/_SSD.h"
#endif
#ifdef USE_FCN
#include "../AI/_FCN.h"
#endif

#define ADD_MODULE(x) if(pK->m_class == #x){return createInst<x>(pK);}

namespace kai
{

class Module
{
public:
	Module();
	virtual ~Module();
	BASE* createInstance(Kiss* pK);
private:
	template <typename T> BASE* createInst(Kiss* pKiss);
};

}

#endif
