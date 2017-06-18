/*
 * town_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/town_class.h"
#include <time.h>
#include <cstdlib>

/* Constructors */
Town::Town()
{
	this->height = 10;
	this->width = 10;
	this->p_vector_case = new std::vector< std::vector<Case*> >();
	this->p_vector_case->resize(this->height, std::vector<Case*>(this->width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(*(this->p_vector_case))[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width)
{
	this->height = height;
	this->width = width;
	this->p_vector_case = new std::vector< std::vector<Case*> >();
	this->p_vector_case->resize(height, std::vector<Case*>(width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(*(this->p_vector_case))[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width, std::vector <std::vector<Case*> >* p_vector_case)
{
	this->height = height;
	this->width = width;
	this->p_vector_case = p_vector_case;
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

void Town::setpVectorCase(std::vector<std::vector<Case*> >*& p_vectorCase)
{
	p_vector_case = p_vectorCase;
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

const std::vector<std::vector<Case*> >* Town::getpVectorCase() const
{
	return p_vector_case;
}

/* Methods */
bool Town::init(unsigned int number_house, unsigned int number_hospital, unsigned int number_fire_station,
		        unsigned int number_total_person, unsigned int number_fireman, unsigned int number_doctor,
				float sick_percent)
{
	/* Check for parameters */
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
	if(0.0 > sick_percent || 100.0 < sick_percent)
	{
		/* Wrong percentage */
		return false;
	}

	/* Place buildings randomly */
	unsigned int rand_row, rand_column;
	srand(time(NULL));
	/* Houses */
	for(unsigned int i=0; i<number_house; ++i)
	{
		do
		{
			rand_row = rand()%this->height;
			rand_column = rand()%this->width;
		} while((*(this->p_vector_case))[rand_row][rand_column]->getType() != Case::field);
		(*(this->p_vector_case))[rand_row][rand_column]->setType(Case::house);
		(*(this->p_vector_case))[rand_row][rand_column]->setNbPersonMax(Case::house_max_people);
		(*(this->p_vector_case))[rand_row][rand_column]->setVectorPerson(std::vector<Person*>());
	}
	/* Hospitals */
	for(unsigned int i=0; i<number_hospital; ++i)
	{
		do
		{
			rand_row = rand()%this->height;
			rand_column = rand()%this->width;
		} while((*(this->p_vector_case))[rand_row][rand_column]->getType() != Case::field);
		(*(this->p_vector_case))[rand_row][rand_column]->setType(Case::hospital);
		(*(this->p_vector_case))[rand_row][rand_column]->setNbPersonMax(Case::hospital_max_people);
		(*(this->p_vector_case))[rand_row][rand_column]->setVectorPerson(std::vector<Person*>());
	}
	/* Fire stations */
	for(unsigned int i=0; i<number_fire_station; ++i)
	{
		do
		{
			rand_row = rand()%this->height;
			rand_column = rand()%this->width;
		} while((*(this->p_vector_case))[rand_row][rand_column]->getType() != Case::field);
		(*(this->p_vector_case))[rand_row][rand_column]->setType(Case::fire_station);
		(*(this->p_vector_case))[rand_row][rand_column]->setNbPersonMax(Case::fire_satation_max_people);
		(*(this->p_vector_case))[rand_row][rand_column]->setVectorPerson(std::vector<Person*>());
	}

	/* Place people randomly, except for firemen and doctors */
	/* TODO */

	/* Infect a percentage of people randomly */
	/* TODO */

	/* Everything goes OK */
	return true;
}
