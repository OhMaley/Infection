/*
 * town_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/town_class.h"
#include "../Includes/doctor_class.h"
#include "../Includes/fireman_class.h"
#include <time.h>
#include <cstdlib>


/* Constructors */
Town::Town()
{
	this->height = 10;
	this->width = 10;
	this->vector_case = std::vector< std::vector<Case*> >();
	this->vector_case.resize(this->height, std::vector<Case*>(this->width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(this->vector_case)[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width)
{
	this->height = height;
	this->width = width;
	this->vector_case = std::vector< std::vector<Case*> >();
	this->vector_case.resize(height, std::vector<Case*>(width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(this->vector_case)[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width, std::vector <std::vector<Case*> > vector_case)
{
	this->height = height;
	this->width = width;
	this->vector_case = vector_case;
}

/* Setters */
void Town::setHeight(unsigned int height)
{
	this->height = height;
}

void Town::setWidth(unsigned int width)
{
	this->width = width;
}

void Town::setVectorCase(const std::vector<std::vector<Case*> >& vector_case)
{
	this->vector_case = vector_case;
}

/* Getters */
unsigned int Town::getHeight() const
{
	return height;
}

unsigned int Town::getWidth() const
{
	return width;
}

const std::vector<std::vector<Case*> > Town::getVectorCase() const
{
	return vector_case;
}

/* Methods */
bool Town::init(unsigned int number_house, unsigned int number_hospital, unsigned int number_fire_station,
		        unsigned int number_total_person, unsigned int number_fireman, unsigned int number_doctor,
				float sick_percent)
{
	/* Check for parameters */
	bool is_param_ok = check_init_parameters(number_house, number_hospital, number_fire_station,
											 number_total_person, number_fireman, number_doctor,
											 sick_percent);
	if(!is_param_ok)
	{
		return false;
	}

	/* Place buildings randomly */
	srand(time(NULL));
	place_buildings_randomly(number_house, Case::house);
	place_buildings_randomly(number_hospital, Case::hospital);
	place_buildings_randomly(number_fire_station, Case::fire_station);

	/* Place people randomly*/
	place_specialized_people_randomly(number_doctor, "doctor");
	place_specialized_people_randomly(number_fireman, "fireman");
	place_other_people_randomly(number_total_person-number_doctor-number_fireman);

	/* Infect a percentage of people randomly */
	infect_people_randomly(sick_percent);

	/* Everything goes OK */
	return true;
}

bool Town::check_init_parameters(unsigned int number_house, unsigned int number_hospital,
								 unsigned int number_fire_station, unsigned int number_total_person,
								 unsigned int number_fireman, unsigned int number_doctor,
								 float sick_percent)
{
	if(number_house + number_hospital + number_fire_station > this->height * this->width)
	{
		/* Too many buildings for the map */
		return false;
	}
	if(number_total_person >
	   number_house * Case::house_max_people +
	   number_hospital * Case::hospital_max_people +
	   number_fire_station * Case::fire_satation_max_people +
	   (this->height * this->width - number_house - number_hospital - number_fire_station) * Case::field_max_people)
	{
		/* Too many people for the map */
		return false;
	}
	if(number_doctor > number_hospital * Case::hospital_max_people ||
	   number_fireman > number_fire_station * Case::fire_satation_max_people)
	{
		/* Too many specialized citizens for their own specialized building */
		return false;
	}
	if(0.0 > sick_percent || 100.0 < sick_percent)
	{
		/* Wrong percentage */
		return false;
	}
	return true;
}
void Town::place_buildings_randomly(unsigned int number_buildings, Case::Case_type case_type)
{
	unsigned int rand_row, rand_column;
	Case::Case_max_people max_people = Case::field_max_people;
	if(Case::house == case_type)
	{
		max_people = Case::house_max_people;
	}
	else if(Case::hospital == case_type)
	{
		max_people = Case::hospital_max_people;
	}
	else if(Case::fire_station == case_type)
	{
		max_people = Case::fire_satation_max_people;
	}
	for(unsigned int i=0; i<number_buildings; ++i)
	{
		do
		{
			rand_row = rand()%this->height;
			rand_column = rand()%this->width;
		} while(Case::field != this->vector_case[rand_row][rand_column]->getType());
		this->vector_case[rand_row][rand_column]->setType(case_type);
		this->vector_case[rand_row][rand_column]->setNbPersonMax(max_people);
		this->vector_case[rand_row][rand_column]->setVectorPerson(std::vector<Person*>());
	}
}

void Town::place_specialized_people_randomly(unsigned int number_person, std::string job)
{
	unsigned int rand_range;
	std::vector<Person*> vector_person = std::vector<Person*>();
	std::vector<Case*> vector_building = std::vector<Case*>();
	Case::Case_type case_type = Case::field;
	if("doctor" == job)
	{
		case_type = Case::hospital;
	}
	else if("fireman" == job)
	{
		case_type = Case::fire_station;
	}
	for(unsigned int i=0; i<this->height; ++i)
	{
		for(unsigned int j=0; j<this->width; ++j)
		{
			if(this->vector_case[i][j]->getType() == case_type)
			{
				vector_building.push_back(this->vector_case[i][j]);
			}
		}
	}
	for(unsigned int i=0; i<number_person; ++i)
	{
		rand_range = rand()%vector_building.size();
		vector_person = vector_building[rand_range]->getVectorPerson();
		if("doctor" == job)
		{
			vector_person.push_back(new Doctor(vector_building[rand_range]));
		}
		else if("fireman" == job)
		{
			vector_person.push_back(new Fireman(vector_building[rand_range]));
		}
		vector_building[rand_range]->setVectorPerson(vector_person);
	}
}

void Town::place_other_people_randomly(unsigned int number_people)
{
	unsigned int rand_row, rand_column;
	std::vector<Person*> vector_person = std::vector<Person*>();
	for(unsigned int i=0; i<number_people; ++i)
	{
		do
		{
			rand_row = rand()%this->height;
			rand_column = rand()%this->width;
		} while(this->vector_case[rand_row][rand_column]->getVectorPerson().size() == this->vector_case[rand_row][rand_column]->getNbPersonMax());
		vector_person = this->vector_case[rand_row][rand_column]->getVectorPerson();
		vector_person.push_back(new Person(this->vector_case[rand_row][rand_column]));
		this->vector_case[rand_row][rand_column]->setVectorPerson(vector_person);
	}
}

void Town::infect_people_randomly(float percent)
{
	unsigned int total_person = 0, number_sick_person, rand_row, rand_column, rand_range;
	bool are_they_all_sick;
	for(unsigned int i=0; i<this->height; ++i)
	{
		for(unsigned int j=0; j<this->width; ++j)
		{
			total_person += this->vector_case[i][j]->getVectorPerson().size();
		}
	}
	number_sick_person = (unsigned int) total_person * percent / 100;
	for(unsigned int i=0; i<number_sick_person; ++i)
	{
		do
		{
			are_they_all_sick = true;
			do
			{
				rand_row = rand()%this->height;
				rand_column = rand()%this->width;
			} while(0 == this->vector_case[rand_row][rand_column]->getVectorPerson().size());
			for(unsigned int j=0; j<this->vector_case[rand_row][rand_column]->getVectorPerson().size(); ++j)
			{
				are_they_all_sick &= this->vector_case[rand_row][rand_column]->getVectorPerson()[j]->getState() == Person::sick;
			}
		} while(are_they_all_sick);
		do
		{
			rand_range = rand()%this->vector_case[rand_row][rand_column]->getVectorPerson().size();
		} while(Person::sick == this->vector_case[rand_row][rand_column]->getVectorPerson()[rand_range]->getState());
		this->vector_case[rand_row][rand_column]->getVectorPerson()[rand_range]->setState(Person::sick);
	}
}
