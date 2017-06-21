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

Doctor::Doctor(Case* p_my_case) : Person(p_my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Person::Person_state state) : Person(life, state)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Case* p_my_case) : Person(life, p_my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, float vaccine) : Person(life)
{
	this->vaccine = vaccine;
}

Doctor::Doctor(float life, Person::Person_state state, Case* p_my_case) : Person(life, state, p_my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Person::Person_state state, float vaccine) : Person(life, state)
{
	this->vaccine = vaccine;
}

Doctor::Doctor(float life, Person::Person_state state, float vaccine, Case* p_my_case) : Person(life, state, p_my_case)
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
void Doctor::heal_person(Person* p_person)
{
	if(0 < this->vaccine)
		{
			float healing_amount = std::min(100 - p_person->getLife(), this->vaccine * 100);
			p_person->setLife(p_person->getLife() + healing_amount);
			this->vaccine -= healing_amount / 100;
		}
}

void Doctor::heal_people_in_case()
{
	if(100 > this->getLife())
	{
		this->heal_person(this);
	}
	for(unsigned int i=0; i<this->getMyCase()->getVectorPerson().size(); ++i)
	{
		if(Person::sick == this->getMyCase()->getVectorPerson()[i]->getState())
		{
			this->heal_person(this->getMyCase()->getVectorPerson()[i]);
		}
	}
}
