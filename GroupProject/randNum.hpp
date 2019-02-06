/****************************************************
 * Author: 		Tim Withers							*
 * Date:		1/30/2019							*
 * Description: All random related functions will	*
 * 				be in this file						*
 ***************************************************/

#ifndef TWITHERS_RANDNUM_HPP
#define TWITHERS_RANDNUM_HPP

float getRandFloat(float min, float max);  // Will get a random num between min and max (It will actually go to max and to min, not like 3.9 if you have 4 as max)
int getRandInt(int min, int max);

#endif
