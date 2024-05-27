/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */
#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>


//#define FT_UAH_EXP_SERV_3_0001
#define FT_UAH_EXP_SERV_129_0002



#ifdef FT_UAH_EXP_SERV_3_0001

#define FT_UAH_EXP_SERV_3_0001_TIME_step0 (UNITIME_AFTER_POWER_ON + 1)
#define FT_UAH_EXP_SERV_3_0001_TIME_step1 (UNITIME_AFTER_POWER_ON + 40)

EmuGSS_TCProgram3_5 prog_FT_UAH_EXP_SERV_3_0001_step_0(FT_UAH_EXP_SERV_3_0001_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 0, Enable SID 10 ",10);

EmuGSS_TCProgram128_1 prog_FT_UAH_EXP_SERV_3_0001_step_1(FT_UAH_EXP_SERV_3_0001_TIME_step1,
"Reboot the system");

#endif


#ifdef FT_UAH_EXP_SERV_129_0002

#define FT_UAH_EXP_SERV_129_0002_TIME_step0 (UNITIME_AFTER_POWER_ON + 1)
#define FT_UAH_EXP_SERV_129_0002_TIME_step1 (UNITIME_AFTER_POWER_ON + 11)
#define FT_UAH_EXP_SERV_129_0002_TIME_step3 (UNITIME_AFTER_POWER_ON + 25)


EmuGSS_TCProgram3_5 prog_FT_0002_step_0(FT_UAH_EXP_SERV_129_0002_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 0, Enable SID 10 ",10);


EmuGSS_TCProgram129_1 prog_FT_0002_step_1(FT_UAH_EXP_SERV_129_0002_TIME_step1,
					"FT_UAH_EXP_SERV_129_0002 step 1, Set Vx=0.2 m/s; Vy=0.2m/s", 0.2, 0.2);



EmuGSS_TCProgram128_1 prog_FT_0002_step_3(FT_UAH_EXP_SERV_129_0002_TIME_step3,
"Reboot the system");

/*
EmuGSS_TCProgram129_2 prog_FT_00XX_step_0(UNITIME_AFTER_POWER_ON + X,
					"FT_UAH_EXP_SERV_129_00XX step 0, Set Command Vx and Vy "
					, XXXX, XXXXX);

*/

#endif


