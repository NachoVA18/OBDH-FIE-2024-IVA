/*
 * icuasw_pus_Service128.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>
#include <public/emu_uah_exp_kinematics.h>

float PUSService129::sFx;
float PUSService129::sFy;
float PUSService129::sFz;

float PUSService129::sCVx = 0;
float PUSService129::sCVy = 0;
//It is not used in Guindance Mode
float PUSService129::sCVz = 0;

float PUSService129::sKpx = 0.1;
float PUSService129::sKpy = 0.1;
float PUSService129::sKpz = 0.1;

class UAHExpEmuKinematic PUSService129::mUAHExpEmulator;

void PUSService129::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {

	case (1):
		PUSService129::Exec129_1TC(tcHandler, tmList);
		break;
	case (2):
		PUSService129::Exec129_2TC(tcHandler, tmList);
		break;
	default:
		break;
	}

}

void PUSService129::Exec129_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {
	float nCVx = tcHandler.GetNextFloat;
	float nCVy = tcHandler.GetNextFloat;

	if(nCVx >= -1.0f && nCVx <= 1.0f && nCVy >= -1.0f && nCVy <= 1.0f){
		sCVx = nCVx;
		sCVy = nCVy;
		PUSService1::BuildTM_1_7(tcHandler, tmList);
	}else{
		if (nCVx < -1.0f || nCVx > 1.0f) {
			PUSService1::BuildTM_1_8_TC_129_1_CVNotValid(tcHandler, tmList, nCVx);
		} else if (nCVy < -1.0f || nCVy > 1.0f) {
			PUSService1::BuildTM_1_8_TC_129_1_CVNotValid(tcHandler, tmList, nCVy);
		}
	}

}

void PUSService129::Exec129_2TC(CDTCHandler &tcHandler, CDTMList &tmList) {
	float nKPx = tcHandler.GetNextFloat;
	float nKPy = tcHandler.GetNextFloat;



	if(nKPx >= 0f && nKPx <= 0.5f && nKPy >= 0f && nKPy <= 0.5f){
		sKpx = tcHandler.GetNextFloat;
		sKpy = tcHandler.GetNextFloat;
		PUSService1::BuildTM_1_7(tcHandler, tmList);
	}else{
		if (nKPx < -1.0f || nKPx > 1.0f) {
			PUSService1::BuildTM_1_8_TC_129_2_KPNotValid(tcHandler, tmList, nKPx);
		} else if (nKPy < -1.0f || nKPy > 1.0f) {
			PUSService1::BuildTM_1_8_TC_129_2_KPNotValid(tcHandler, tmList, nKPy);
		}
	}
}

const float ActuatorMAX_X_Y_Newtons = 0.100; //100 MiliNewtons
const float ActuatorMAX_Z_Newtons = 1.000; //1 Newton

float PUSService129::LimitActuator(float F, float Limit) {

	float maxF = F;
	if (maxF > Limit)
		maxF = Limit;
	else if (maxF < (-Limit)) {
		maxF = -Limit;
	}
	return maxF;
}

void PUSService129::GuidanceControl() {

	struct UAHExpKinematic currentKinematic;

	//Update Kinematic with the previous values of Fx, sFy y sFz.

	currentKinematic = mUAHExpEmulator.EmuKinematic(sFx, sFy, sFz);

	//Calculate Forces to apply in the next period:
	sFx = (sCVx - currentKinematic.Vx) * sKpx;
	sFy = (sCVy - currentKinematic.Vy) * sKpy;
	//sFz = (sCVz - currentVeloc.Vz) * sKpz;

	//
	sFx=LimitActuator(sFx,ActuatorMAX_X_Y_Newtons);
	sFy=LimitActuator(sFy,ActuatorMAX_X_Y_Newtons);

	//Fz is only due to Gravity
	/*
	if (sFz >= 0)
		sFz = 0;
	else {
		sFz=LimitActuator(sFz,ActuatorMAX_Z_Newtons);

	}*/

	uint16_t VxScaled, VyScaled, VzScaled, MassScaled;

	//Store in SystemDataPool a scaled version of Vx, Vy, Vz and Mass
	VxScaled = currentKinematic.Vx * 32768 + 32768;
	VyScaled = currentKinematic.Vy * 32768 + 32768;
	VzScaled = currentKinematic.Vz * 65; //
	MassScaled = currentKinematic.Mass* 65535;

	//Set SystemDataPool parameters
	SystemDataPool::SetFromInt16(5, VxScaled);
	SystemDataPool::SetFromInt16(6, VyScaled);
	SystemDataPool::SetFromInt16(7, VzScaled);
	SystemDataPool::SetFromInt16(8, MassScaled);

}
