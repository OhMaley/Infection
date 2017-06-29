/*
 * fireman_class.h
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */

#ifndef FIREMAN_CLASS_H_
#define FIREMAN_CLASS_H_

#include "person_class.h"


class Fireman : public Person
{
	public:
		/* Constructors */
		Fireman(Case* my_case);
		Fireman(float life, Case* my_case);
		Fireman(float life, unsigned int firebomb);
		Fireman(float life, Person::Person_state state, Case* my_case);
		Fireman(float life = 100.0, Person::Person_state state = healthy, unsigned int firebomb = 4, Case* my_case = new Case());

		/* Setter */
		void setFirebomb(unsigned int firebomb);

		/* Getter */
		unsigned int getFirebomb() const;

		/* Method */
		void burn_corpse_in_my_case();

	private:
		/* Attribute */
		unsigned int firebomb;
};


#endif /* FIREMAN_CLASS_H_ */
