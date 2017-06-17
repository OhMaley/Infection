/*
 * person_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/person_class.h"

/* Constructors */
Person::Person()
{
	life = 100;
	state = healthy;
}

Person::Person(float init_life)
{
	life = init_life;
	state = healthy;
}

Person::Person(float init_life, Person::Person_state init_state)
{
	life = init_life;
	state = init_state;
}

/* Setters */
void Person::setLife(float life)
{
	this->life = life;
}

void Person::setState(Person::Person_state state)
{
	this->state = state;
}

/* Getters */
float Person::getLife() const
{
	return life;
}

Person::Person_state Person::getState() const
{
	return state;
}
