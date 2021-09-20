/*
 * state.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fury Word
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

#define STATE_DEFINE(_statfunc) void ST_##_statfunc()
#define STATE(_statfunc) ST_##_statfunc

/*States connections*/
void HP_setPressVal(int pressure);
void HP_startAlarm();
void HP_stopAlarm();
void HP_hpDetected();

/*For global debugging -High pressure detection system-*/
//#define HP_DEBUG
#endif /* INC_STATE_H_ */
