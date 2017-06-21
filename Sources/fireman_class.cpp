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

Fireman::Fireman(Case* p_my_case) : Person(p_my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Person::Person_state state) : Person(life, state)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Case* p_my_case) : Person(life, p_my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, unsigned int firebomb) : Person(life)
{
	this->firebomb = firebomb;
}

Fireman::Fireman(float life, Person::Person_state state, Case* p_my_case) : Person(life, state, p_my_case)
{
	this->firebomb = 4;
}

Fireman::Fireman(float life, Person::Person_state state, unsigned int firebomb) : Person(life, state)
{
	this->firebomb = firebomb;
}

Fireman::Fireman(float life, Person::Person_state state, unsigned int firebomb, Case* p_my_case) : Person(life, state, p_my_case)
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
		std::vector<unsigned int> vector_index_dead_person = std::vector<unsigned int>();
		for(unsigned int i=0; i<this->p_my_case->getVectorPerson().size(); ++i)
		{
			if(Person::dead == this->p_my_case->getVectorPerson()[i]->getState())
			{
				vector_index_dead_person.push_back(i);
			}
		}
		if(0 < vector_index_dead_person.size())
		{
			this->firebomb -= 1;
			std::vector<Person*> vector_person = this->p_my_case->getVectorPerson();
			for(int i=vector_index_dead_person.size()-1; i>=0; --i)
			{
				vector_person.erase(vector_person.begin() + vector_index_dead_person[i]);
			}
			this->p_my_case->setVectorPerson(vector_person);
		}
	}
}
