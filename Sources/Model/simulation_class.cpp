/*
 * simulation_class.cpp
 *
 *  Created on: 30 juin 2017
 *      Author: Tristan
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include "../../Includes/Model/simulation_class.h"
#include "../../Includes/Model/fireman_class.h"
#include "../../Includes/Model/doctor_class.h"


/* Constructor */
Simulation::Simulation(Town* town, InfectionParameters infection_parameters)
{
	std::vector<Town*> vector_town_each_round = std::vector<Town*>();
	vector_town_each_round.push_back(town);
	this->vector_town_each_round = vector_town_each_round;
	this->actual_round = 0;
	this->infection_parameters = infection_parameters;
}

/* Setters */
void Simulation::setVectorTownEachRound(const std::vector<Town*>& vectorTownEachRound)
{
	vector_town_each_round = vectorTownEachRound;
}

void Simulation::setActualRound(unsigned int actualRound)
{
	actual_round = actualRound;
}

void Simulation::setProbInfectSameCase(float probInfectSameCase)
{
	this->infection_parameters.prob_infect_same_case = probInfectSameCase;
}

void Simulation::setProbInfectNearCase(float probInfectNearCase)
{
	this->infection_parameters.prob_infect_near_case = probInfectNearCase;
}

void Simulation::setProbMultDead(float probMultDead)
{
	this->infection_parameters.prob_mult_dead = probMultDead;
}

void Simulation::setProbMultFireman(float probMultFireman)
{
	this->infection_parameters.prob_mult_fireman = probMultFireman;
}

void Simulation::setProbMultHospital(float probMultHospital)
{
	this->infection_parameters.prob_mult_hospital = probMultHospital;
}

void Simulation::setProbMultFireStation(float probMultFireStation)
{
	this->infection_parameters.prob_mult_fire_station = probMultFireStation;
}

void Simulation::setLoseLifeWhenSick(float loseLifeWhenSick)
{
	this->infection_parameters.lose_life_when_sick = loseLifeWhenSick;
}

/* Getters */
const std::vector<Town*>& Simulation::getVectorTownEachRound() const
{
	return vector_town_each_round;
}

unsigned int Simulation::getActualRound() const
{
	return actual_round;
}

float Simulation::getProbInfectSameCase() const
{
	return infection_parameters.prob_infect_same_case;
}

float Simulation::getProbInfectNearCase() const
{
	return infection_parameters.prob_infect_near_case;
}

float Simulation::getProbMultDead() const
{
	return infection_parameters.prob_mult_dead;
}

float Simulation::getProbMultFireman() const
{
	return infection_parameters.prob_mult_fireman;
}

float Simulation::getProbMultHospital() const
{
	return infection_parameters.prob_mult_hospital;
}

float Simulation::getProbMultFireStation() const
{
	return infection_parameters.prob_mult_fire_station;
}

float Simulation::getLoseLifeWhenSick() const
{
	return infection_parameters.lose_life_when_sick;
}

/* Methods */
void Simulation::next_round()
{
	/* Manage the case of we'r coming from an already computed nex_round (in case of previous 'previous round') */
	if(this->getActualRound() +1 < this->getVectorTownEachRound().size())
	{
		this->setActualRound(this->getActualRound() + 1);
	}
	/* New next round, unless everybody is dead */
	else if(!this->is_over())
	{
		/* Create a copy of the actual town to work on it for this new round */
		std::vector<Town*> vector_town = this->getVectorTownEachRound();
		vector_town.push_back(vector_town[this->getActualRound()]);
		this->setVectorTownEachRound(vector_town);
		/* Increase the round number */
		this->setActualRound(this->getActualRound() + 1);
		/* do all the thing for the round */
		move_people_randomly();
		virus_propagation();
	}
}

void Simulation::previous_round()
{
	/* Can't go previous if it's the 1st round */
	if(0 < this->getActualRound())
	{
		/* Just decrement the actual round in the vector of town for each round */
		this->setActualRound(this->getActualRound() - 1);
	}
}

bool Simulation::is_over()
{
	bool are_they_all_dead = true;
	bool is_no_more_virus = true;
	for(unsigned int i=0; i<this->getVectorTownEachRound()[this->getActualRound()]->getHeight(); ++i)
	{
		for(unsigned int j=0; j<this->getVectorTownEachRound()[this->getActualRound()]->getWidth(); ++j)
		{
			for(unsigned int k=0; k<this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson().size(); ++k)
			{
				are_they_all_dead &= !(this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson()[k]->is_alive());
				is_no_more_virus &= this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson()[k]->getState() == Person::healthy;
			}
		}
	}
	if(are_they_all_dead || is_no_more_virus)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Simulation::fulfill_near_case_to_move(std::vector<Case*> *vector_case_to_move, unsigned int row, unsigned int column)
{
	for(unsigned int i=std::max((int) row-1, 0); i<=std::min(row+1, this->getVectorTownEachRound()[this->getActualRound()]->getHeight()-1); ++i)
	{
		for(unsigned int j=std::max((int) column-1, 0); j<=std::min(column+1, this->getVectorTownEachRound()[this->getActualRound()]->getWidth()-1); ++j)
		{
			vector_case_to_move->push_back(this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]);
		}
	}
}

void Simulation::move_person_randomly(Person* person, unsigned int position_in_case)
{
	std::vector<Case*> vector_case_to_move = std::vector<Case*>();
	unsigned int rand_index = 0;
	/* Get a vector of near case where the person can move */
	fulfill_near_case_to_move(&vector_case_to_move, person->getMyCase()->getRow(), person->getMyCase()->getColumn());
	/* remove the person from the original case */
	std::vector<Person*> vector_person = person->getMyCase()->getVectorPerson();
	vector_person.erase(vector_person.begin() + position_in_case);
	person->getMyCase()->setVectorPerson(vector_person);
	/* Pick randomly a new case to move in the near non-full case */
	do
	{
		rand_index = rand()%vector_case_to_move.size();
	} while(vector_case_to_move[rand_index]->getVectorPerson().size() == vector_case_to_move[rand_index]->getNbPersonMax());
	/* Add the person in the new case */
	vector_person = vector_case_to_move[rand_index]->getVectorPerson();
	vector_person.push_back(person);
	vector_case_to_move[rand_index]->setVectorPerson(vector_person);
	/* Update my_case person attribute  */
	person->setMyCase(vector_case_to_move[rand_index]);
}

void Simulation::move_people_randomly()
{
	std::vector<unsigned int> people_moved = std::vector<unsigned int>();
	unsigned int id=0;
	unsigned int vector_size = 0;
	unsigned int l=0;
	srand(time(NULL));
	for(unsigned int i=0; i<this->getVectorTownEachRound()[this->getActualRound()]->getHeight(); ++i)
	{
		for(unsigned int j=0; j<this->getVectorTownEachRound()[this->getActualRound()]->getWidth(); ++j)
		{
			vector_size = this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson().size();
			l=0;
			for(unsigned int k=0; k<vector_size; ++k)
			{
				id = this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson()[l]->getId();
				if(std::find(people_moved.begin(), people_moved.end(), id) == people_moved.end())
				{
					move_person_randomly(this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson()[l], l);
					people_moved.push_back(id);
				}
				else
				{
					++l;
				}
			}
		}
	}
}

void Simulation::lose_life(Person* person)
{
	float remaining_life = std::max((float)0, person->getLife()-this->getLoseLifeWhenSick());
	person->setLife(remaining_life);
	if(person->getLife() <= 0)
	{
		person->setState(Person::dead);
	}
}

void Simulation::infect_by_people_in_same_case(Person* person, unsigned int position_in_case)
{
	float prob_be_infected = 0;
	Person* neighbour = NULL;
	std::vector<Person*> vector_person = person->getMyCase()->getVectorPerson();
	vector_person.erase(vector_person.begin() + position_in_case);
	/* Compute the probability to be infected by each neighbor and let the probability decide */
	for(unsigned int i=0; i<vector_person.size(); ++i)
	{
		neighbour = vector_person[i];
		prob_be_infected = 0;
		if(neighbour->getState() != Person::healthy)
		{
			prob_be_infected = this->getProbInfectSameCase();
			if(neighbour->getState() == Person::dead)
			{
				prob_be_infected *= this->getProbMultDead();
			}
			else if(dynamic_cast<Fireman*>(neighbour) != NULL)
			{
				prob_be_infected *= this->getProbMultFireman();
			}
			if(person->getMyCase()->getType() == Case::hospital)
			{
				prob_be_infected *= this->getProbMultHospital();
			}
			else if(person->getMyCase()->getType() == Case::fire_station)
			{
				prob_be_infected *= this->getProbMultFireStation();
			}
		}
		/* Let the probability decide the state of the person */
		if(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) <= prob_be_infected)
		{
			person->setState(Person::sick);
			/* Stop the loop, he is sick */
			break;
		}
	}
}

void Simulation::infect_by_people_in_near_case(Person* person)
{
	float prob_be_infected = 0;
	Person* neighbour = NULL;

	std::vector<Person*> vector_person = std::vector<Person*>();
	std::vector<Case*> vector_case_to_move = std::vector<Case*>();
	/* Get a vector of near case */
	fulfill_near_case_to_move(&vector_case_to_move, person->getMyCase()->getRow(), person->getMyCase()->getColumn());
	/* Create a vector of all near person */
	for(unsigned int i=0; i<vector_case_to_move.size(); ++i)
	{
		for(unsigned int j=0; j<vector_case_to_move[i]->getVectorPerson().size(); ++j)
		{
			vector_person.push_back(vector_case_to_move[i]->getVectorPerson()[j]);
		}
	}

	/* Compute the probability to be infected by each neighbor and let the probability decide */
	for(unsigned int i=0; i<vector_person.size(); ++i)
	{
		neighbour = vector_person[i];
		prob_be_infected = 0;
		if(neighbour->getState() != Person::healthy)
		{
			prob_be_infected = this->getProbInfectNearCase();
			if(neighbour->getState() == Person::dead)
			{
				prob_be_infected *= this->getProbMultDead();
			}
			else if(dynamic_cast<Fireman*>(neighbour) != NULL)
			{
				prob_be_infected *= this->getProbMultFireman();
			}
			if(person->getMyCase()->getType() == Case::hospital)
			{
				prob_be_infected *= this->getProbMultHospital();
			}
			else if(person->getMyCase()->getType() == Case::fire_station)
			{
				prob_be_infected *= this->getProbMultFireStation();
			}
		}
		/* Let the probability decide the state of the person */
		if(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) <= prob_be_infected)
		{
			person->setState(Person::sick);
			/* Stop the loop, he is sick */
			break;
		}
	}
}

void Simulation::virus_propagation()
{
	Person* person = NULL;
	for(unsigned int i=0; i<this->getVectorTownEachRound()[this->getActualRound()]->getHeight(); ++i)
	{
		for(unsigned int j=0; j<this->getVectorTownEachRound()[this->getActualRound()]->getWidth(); ++j)
		{
			for(unsigned int k=0; k<this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson().size(); ++k)
			{
				person = this->getVectorTownEachRound()[this->getActualRound()]->getVectorCase()[i][j]->getVectorPerson()[k];
				if(person->getState() == Person::healthy)
				{
					infect_by_people_in_same_case(person, k);
					infect_by_people_in_near_case(person);
				}
				if(person->getState() == Person::sick)
				{
					lose_life(person);
				}
				person_action(person);
			}
		}
	}
}

void Simulation::person_action(Person* person)
{
	/* If the person is a doctor */
	if(dynamic_cast<Doctor*>(person) != NULL)
	{
		/* If the doctor is in a hospital, give him some vaccine */
		if(dynamic_cast<Doctor*>(person)->getMyCase()->getType() == Case::hospital)
		{
			dynamic_cast<Doctor*>(person)->setVaccine(dynamic_cast<Doctor*>(person)->getMaxVaccine());
		}
		/* Heal people in the same case */
		dynamic_cast<Doctor*>(person)->heal_people_in_my_case();
	}
	/* If the person is a fireman */
	else if(dynamic_cast<Fireman*>(person) != NULL)
	{
		/* If the fireman is in a fire station, give him some firebomb */
		if(dynamic_cast<Fireman*>(person)->getMyCase()->getType() == Case::fire_station)
		{
			dynamic_cast<Fireman*>(person)->setFirebomb(dynamic_cast<Fireman*>(person)->getMaxFirebomb());
		}
		/* Burn corpses in the same case */
		dynamic_cast<Fireman*>(person)->burn_corpse_in_my_case();
	}
}
