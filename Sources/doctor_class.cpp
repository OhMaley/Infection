/*
 * Doctor.cpp
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */


#include "../Includes/doctor_class.h"


/* Constructors */
Doctor::Doctor() : Person()
{
	this->vaccine = 4;
}

Doctor::Doctor(float life) : Person(life)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Person::Person_state state) : Person(life, state)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, float vaccine) : Person(life)
{
	this->vaccine = vaccine;
}

Doctor::Doctor(float life, Person::Person_state state, float vaccine) : Person(life, state)
{
	this->vaccine = vaccine;
}

/* Setters */
void Doctor::setVaccine(float vaccine)
{
	this->vaccine = vaccine;
}

/* Getters */
float Doctor::getVaccine() const
{
	return vaccine;
}

/* Method */
void Doctor::heal(Person* p_person)
{
	/* TODO */
}
