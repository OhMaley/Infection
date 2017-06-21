/*
 * fireman_class.h
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */

#ifndef FIREMAN_CLASS_H_
#define FIREMAN_CLASS_H_

#include "../Includes/person_class.h"


class Fireman : public Person
{
	public:
		/* Constructors */
		Fireman();
		Fireman(float life);
		Fireman(Case* p_my_case);
		Fireman(float life, Person::Person_state state);
		Fireman(float life, Case* p_my_case);
		Fireman(float life, unsigned int firebomb);
		Fireman(float life, Person::Person_state state, Case* p_my_case);
		Fireman(float life, Person::Person_state state, unsigned int firebomb);
		Fireman(float life, Person::Person_state state, unsigned int firebomb, Case* p_my_case);

		/* Setter */
		void setFirebomb(unsigned int firebomb);

		/* Getter */
		unsigned int getFirebomb() const;

		/* Method */
		void burn_corpse();

	private:
		/* Attribute */
		unsigned int firebomb;
};


#endif /* FIREMAN_CLASS_H_ */
