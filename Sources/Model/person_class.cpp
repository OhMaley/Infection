/*
 * person_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../../Includes/Model/person_class.h"


/* Constructors */
Person::Person(Case* my_case)
{
	this->ID = this->Count_total_instance();
	this->life = 100;
	this->state = healthy;
	this->my_case = my_case;
}

Person::Person(float life, Case* my_case)
{
	this->ID = this->Count_total_instance();
	this->life = life;
	this->state = healthy;
	this->my_case = my_case;
}

Person::Person(float life, Person_state state, Case* my_case)
{
	this->ID = this->Count_total_instance();
	this->life = life;
	this->state = state;
	this->my_case = my_case;
}

/* Setters */
void Person::setId(unsigned int ID)
{
	this->ID = ID;
}

void Person::setLife(float life)
{
	this->life = life;
}

void Person::setState(Person::Person_state state)
{
	this->state = state;
}

void Person::setMyCase(Case* my_case)
{
	this->my_case = my_case;
}

/* Getters */
unsigned int Person::getId() const
{
	return ID;
}

float Person::getLife() const
{
	return life;
}

Person::Person_state Person::getState() const
{
	return state;
}

Case* Person::getMyCase() const
{
	return my_case;
}

/* Method */
bool Person::is_alive() const
{
	return this->state != Person::dead;
}
