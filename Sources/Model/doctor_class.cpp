/*
 * Doctor.cpp
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */


#include "../../Includes/Model/doctor_class.h"


/* Constructors */
Doctor::Doctor(Case* my_case) : Person(my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Case* my_case) : Person(life, my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, float vaccine) : Person(life)
{
	this->vaccine = vaccine;
}

Doctor::Doctor(float life, Person::Person_state state, Case* my_case) : Person(life, state, my_case)
{
	this->vaccine = 4;
}

Doctor::Doctor(float life, Person::Person_state state, float vaccine, Case* my_case) : Person(life, state, my_case)
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
	/* Only heal if the doctor still have vaccine and if the person is alive */
	if(0 < this->vaccine && p_person->is_alive())
		{
			/* Heal for remaining vaccine or for the lack of life of the person */
			float healing_amount = std::min(100 - p_person->getLife(), this->vaccine * 100);
			p_person->setLife(p_person->getLife() + healing_amount);
			this->vaccine -= healing_amount / 100;
			/* And if the person is sick cure him */
			if(Person::sick == p_person->getState())
			{
				this->setState(Person::healthy);
			}
		}
}

void Doctor::heal_people_in_my_case()
{
	/* Heal the doctor first if needed */
	if(100 > this->getLife() || Person::sick == this->getState())
	{
		this->heal_person(this);
	}
	/* Then heal every alive person in the same case if needed */
	std::vector<Person*> vector_person = this->getMyCase()->getVectorPerson();
	for(std::vector<Person*>::iterator it = vector_person.begin(); it != vector_person.end(); ++it)
	{
		if((*it)->is_alive() && (100 > (*it)->getLife() || Person::sick == (*it)->getState()))
		{
			this->heal_person(*it);
		}
	}
}
