/*
 * _DNNodometryTrain.h
 *
 *  Created on: May 17, 2017
 *      Author: yankai
 */

#ifndef OPENKAI_SRC_Odometry__DNNodometryTrain_H_
#define OPENKAI_SRC_Odometry__DNNodometryTrain_H_

#include "../Base/common.h"
#include "../Base/_ThreadBase.h"
#include "../DNN/_ImageNet.h"
#include "../Vision/_ZED.h"
#include "../Vision/_Flow.h"
#include "../Utility/util.h"

namespace kai
{

class _DNNodometryTrain: public _ThreadBase
{
public:
	_DNNodometryTrain(void);
	virtual ~_DNNodometryTrain();

	bool init(void* pKiss);
	bool link(void);
	bool start(void);
	bool draw(void);

private:
	void update(void);
	static void* getUpdateThread(void* This)
	{
		((_DNNodometryTrain *) This)->update();
		return NULL;
	}

public:
	_ZED* m_pZED;
	_ImageNet* m_pIN;
	vDouble3	m_attiRad;	//yaw, pitch, roll, heading

	uint64_t	m_tNow;
};

}

#endif
