/*
 * infection_parameters.h
 *
 *  Created on: 4 juil. 2017
 *      Author: Tristan
 */

#ifndef INFECTION_PARAMETERS_H_
#define INFECTION_PARAMETERS_H_


struct InfectionParameters
{
	InfectionParameters(float prob_infect_same_case = 0.15, float prob_infect_near_case = 0.05, float prob_mult_dead = 1.5,
						float prob_mult_fireman = 0.25, float prob_mult_hospital = 0.0, float prob_mult_fire_station = 0.25,
						float lose_life_when_sick = 20.0)
	{
		this->prob_infect_same_case = prob_infect_same_case;
		this->prob_infect_near_case = prob_infect_near_case;
		this->prob_mult_dead = prob_mult_dead;
		this->prob_mult_fireman = prob_mult_fireman;
		this->prob_mult_hospital = prob_mult_hospital;
		this->prob_mult_fire_station = prob_mult_fire_station,
		this->lose_life_when_sick = lose_life_when_sick;
	}

	float prob_infect_same_case;
	float prob_infect_near_case;
	float prob_mult_dead;
	float prob_mult_fireman;
	float prob_mult_hospital;
	float prob_mult_fire_station;
	float lose_life_when_sick;
};


#endif /* INFECTION_PARAMETERS_H_ */
