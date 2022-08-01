
#ifndef STATE_H_
#define STATE_H_

#define STATE_DEFINE(_statfunc) void ST_##_statfunc()
#define STATE(_statfunc) ST_##_statfunc

/*States connections*/
void US_set_distance(int d);
void DC_motor_set(int s);

#endif /* STATE_H_ */
