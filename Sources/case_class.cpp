/*
 * case_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/case_class.h"


/* Constructors */
Case::Case()
{
	type = Case::field;
	nb_person_max = Case::field_max_people;
	vector_person = std::vector<Person*>();
}

Case::Case(Case::Case_type init_type)
{
	type = init_type;
	nb_person_max = Case::field_max_people;
	vector_person = std::vector<Person*>();
}

Case::Case(Case::Case_type init_type, unsigned int init_nb_person_max, std::vector<Person*> init_vector_person)
{
	type = init_type;
	nb_person_max = init_nb_person_max;
	vector_person = init_vector_person;
}

/* Setters */
void Case::setNbPersonMax(unsigned int nb_person_max)
{
	this->nb_person_max = nb_person_max;
}

void Case::setType(Case::Case_type type)
{
	this->type = type;
}

void Case::setVectorPerson(const std::vector<Person*>& vector_person)
{
		this->vector_person = vector_person;
}

/* Getters */
unsigned int Case::getNbPersonMax() const
{
	return nb_person_max;
}

Case::Case_type Case::getType() const
{
	return type;
}

const std::vector<Person*>& Case::getVectorPerson() const
{
	return vector_person;
}
