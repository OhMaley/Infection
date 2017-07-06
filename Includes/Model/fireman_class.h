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
		Fireman(Case* my_case = new Case());
		Fireman(float life = 100.0, Case* my_case = new Case());
		Fireman(float life = 100.0, unsigned int firebomb = 4, unsigned int max_firebomb = 4);
		Fireman(float life = 100.0, Person::Person_state state = healthy, Case* my_case = new Case());
		Fireman(float life = 100.0, Person::Person_state state = healthy, unsigned int firebomb = 4, unsigned int max_firebomb = 4, Case* my_case = new Case());

		/* Setter */
		void setFirebomb(unsigned int firebomb);
		void setMaxFirebomb(unsigned int max_firebomb);

		/* Getter */
		unsigned int getFirebomb() const;
		unsigned int getMaxFirebomb() const;

		/* Method */
		void burn_corpse_in_my_case();

	private:
		/* Attribute */
		unsigned int firebomb;
		unsigned int max_firebomb;
};


#endif /* FIREMAN_CLASS_H_ */
