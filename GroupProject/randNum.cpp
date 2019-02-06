/****************************************************
 * Author: 		Tim Withers							*
 * Date:		1/30/2019							*
 * Description: All random related functions will	*
 * 				be in this file						*
 ***************************************************/
#include <random>

float getRandFloat(float min, float max){
	std::random_device randDev;
	std::mt19937 generator(randDev());
	std::uniform_real_distribution<> distr(min, max);

	return distr(generator);
}

int getRandInt(int min, int max) {
	std::random_device randDev;
	std::mt19937 generator(randDev());
	std::uniform_int_distribution<> distr(min, max);

	return distr(generator);
}
