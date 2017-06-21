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
	this->life = 100;
	this->state = healthy;
	this->p_my_case = new Case();
}

Person::Person(float life)
{
	this->life = life;
	this->state = healthy;
	this->p_my_case = new Case();
}

Person::Person(Case* p_my_case)
{
	this->life = 100;
	this->state = healthy;
	this->p_my_case = p_my_case;
}

Person::Person(float life, Person::Person_state state)
{
	this->life = life;
	this->state = state;
	this->p_my_case = new Case();
}

Person::Person(float life, Case* p_my_case)
{
	this->life = life;
	this->state = healthy;
	this->p_my_case = p_my_case;
}

Person::Person(float life, Person_state state, Case* p_my_case)
{
	this->life = life;
	this->state = state;
	this->p_my_case = p_my_case;
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

void Person::setMyCase(Case*& p_my_case)
{
	this->p_my_case = p_my_case;
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

const Case* Person::getMyCase() const
{
	return p_my_case;
}

/* Method */
bool Person::is_alive() const
{
	return this->state != Person::dead;
}
