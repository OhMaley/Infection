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
		void setVectorTownEachRound(const std::vector<Town*>& vectorTownEachRound);
		void setActualRound(unsigned int actualRound);
		void setProbInfectSameCase(float probInfectSameCase);
		void setProbInfectNearCase(float probInfectNearCase);
		void setProbMultDead(float probMultDead);
		void setProbMultFireman(float probMultFireman);
		void setProbMultHospital(float probMultHospital);
		void setProbMultFireStation(float probMultFireStation);
		void setLoseLifeWhenSick(float loseLifeWhenSick);

		/* Getters */
		const std::vector<Town*>& getVectorTownEachRound() const;
		unsigned int getActualRound() const;
		float getProbInfectSameCase() const;
		float getProbInfectNearCase() const;
		float getProbMultDead() const;
		float getProbMultFireman() const;
		float getProbMultHospital() const;
		float getProbMultFireStation() const;
		float getLoseLifeWhenSick() const;

		/* Methods */
		void next_round();
		void previous_round();
		bool is_over();
		void fulfill_near_case_to_move(std::vector<Case*> *vector_case_to_move, unsigned int row, unsigned int column);
		void move_person_randomly(Person* person, unsigned int position_in_case);
		void move_people_randomly();
		void infect_by_people_in_same_case(Person* person, unsigned int position_in_case);
		void infect_by_people_in_near_case(Person* person);
		void lose_life(Person* person);
		void virus_propagation();
		void person_action(Person* person);

	private:
		/* Attributes */
		std::vector<Town*> vector_town_each_round;
		unsigned int actual_round;
		InfectionParameters infection_parameters;
};


#endif /* SIMULATION_CLASS_H_ */
