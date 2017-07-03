/*
 * simulaion_class.h
 *
 *  Created on: 30 juin 2017
 *      Author: Tristan
 */

#ifndef SIMULATION_CLASS_H_
#define SIMULATION_CLASS_H_


#include "town_class.h"
#include "person_class.h"

class Simulation
{
	public:
		/* Constructor */
		Simulation(Town* town = new Town,
				   float prob_infect_same_case = 0.15, float prob_infect_near_case = 0.05,
				   float prob_mult_dead = 1.5, float prob_mult_fireman = 0.25,
				   float prob_mult_hospital = 0, float prob_mult_fire_station = 0.25);

		/* Setters */
		void setTown(Town*& town);
		void setProbInfectSameCase(float probInfectSameCase);
		void setProbInfectNearCase(float probInfectNearCase);
		void setProbMultDead(float probMultDead);
		void setProbMultFireman(float probMultFireman);
		void setProbMultHospital(float probMultHospital);
		void setProbMultFireStation(float probMultFireStation);

		/* Getters */
		const Town* getTown() const;
		float getProbInfectSameCase() const;
		float getProbInfectNearCase() const;
		float getProbMultDead() const;
		float getProbMultFireman() const;
		float getProbMultHospital() const;
		float getProbMultFireStation() const;

		/* Methods */
		void next_round();
		void previous_round();
		void fulfill_near_case_to_move(std::vector<Case*> *vector_case_to_move, unsigned int row, unsigned int column);
		void move_person_randomly(Person* person, unsigned int position_in_case);
		void move_people_randomly();
		void infect_by_people_in_same_case(Person* person, unsigned int position_in_case);
		void infect_by_people_in_near_case(Person*, unsigned int position_in_case);
		void compute_person_state(Person* person);
		void virus_propagation();
		void people_action();

	private:
		/* Attributes */
		Town* town;
		float prob_infect_same_case;
		float prob_infect_near_case;
		float prob_mult_dead;
		float prob_mult_fireman;
		float prob_mult_hospital;
		float prob_mult_fire_station;
};


#endif /* SIMULATION_CLASS_H_ */
