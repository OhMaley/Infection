/*
 * fireman_class.cpp
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */


#include "../../Includes/Model/fireman_class.h"


/* Constructors */
Fireman::Fireman(Case* my_case) : Person(my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Case* my_case) : Person(life, my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, unsigned int firebomb) : Person(life)
{
	this->firebomb = firebomb;
}

Fireman::Fireman(float life, Person::Person_state state, Case* my_case) : Person(life, state, my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Person::Person_state state, unsigned int firebomb, Case* my_case) : Person(life, state, my_case)
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
void Fireman::burn_corpse_in_my_case()
{
	/* Burn corpse only if the fireman still have a firebomb */
	if(0 < this->firebomb)
	{
		std::vector<unsigned int> vector_index_dead_person = std::vector<unsigned int>();
		std::vector<Person*> vector_person = this->getMyCase()->getVectorPerson();
		/* Find and store the index of the dead person in the fireman case */
		for(std::vector<Person*>::iterator it = vector_person.begin(); it != vector_person.end(); ++it)
		{
			if(!(*it)->is_alive())
			{
				vector_index_dead_person.push_back(it - vector_person.begin());
			}
		}
		/* If there are dead people */
		if(0 < vector_index_dead_person.size())
		{
			/* Use a firebomb to delete this dead person from the fireman case */
			this->firebomb -= 1;
			for(unsigned int i=vector_index_dead_person.size(); i>0; --i)
			{
				vector_person.erase(vector_person.begin() + vector_index_dead_person[i-1]);
			}
			this->getMyCase()->setVectorPerson(vector_person);
		}
	}
}
