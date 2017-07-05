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
#include "infection_parameters.h"

class Simulation
{
	public:
		/* Constructor */
		Simulation(Town* town = new Town, InfectionParameters infection_parameters = InfectionParameters());

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
		InfectionParameters infection_parameters;
};


#endif /* SIMULATION_CLASS_H_ */
