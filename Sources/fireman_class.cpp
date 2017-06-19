/*
 * fireman_class.cpp
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */


#include "../Includes/fireman_class.h"


/* Constructors */
Fireman::Fireman() : Person()
{
	this->firebomb = 4;
}

Fireman::Fireman(float life) : Person(life)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Person::Person_state state) : Person(life, state)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, unsigned int firebomb) : Person(life)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Person::Person_state state, unsigned int firebomb) : Person(life, state)
{
	this->firebomb = firebomb;
}

/* Setters */
void Fireman::setFirebomb(unsigned int firebomb)
{
	this->firebomb = firebomb;
}

/* Getters */
unsigned int Fireman::getFirebomb() const
{
	return firebomb;
}

/* Method */
void Fireman::burn_corpse()
{
	if(0 < this->firebomb)
	{
		for(unsigned int i=0; i<this->p_my_case->getVectorPerson().size(); ++i)
		{
			if(Person::dead == this->p_my_case->getVectorPerson()[i]->getState())
			{
				/* TODO */
				/* this->p_my_case->getVectorPerson().erase(this->p_my_case->getVectorPerson().begin() + i); */
			}
		}
	}
}
