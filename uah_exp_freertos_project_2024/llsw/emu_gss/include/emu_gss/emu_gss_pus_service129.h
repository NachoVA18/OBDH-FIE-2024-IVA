/*
 * emu_gss_pus_service129.h
 *
 *  Created on: 27 may 2024
 *      Author: atcsol
 */

#ifndef EMU_SC_PUS_SERVICE129_H_
#define EMU_SC_PUS_SERVICE129_H_


class EmuGSS_TCProgram129_1:public EmuGSS_TCProgram{

	float mCVx;
	float mCVy;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram129_1(uint32_t uniTime2YK,
                 const char * brief,float mCVx, float mCVy);

};



class EmuGSS_TCProgram129_2:public EmuGSS_TCProgram{

	float mKpx;
	float mKpy;


	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram129_2(uint32_t uniTime2YK,
                 const char * brief,float mKpx, float mKpy);

};



#endif /* EMU_SC_PUS_SERVICE129_H_ */
