/*
 * doctor_class.h
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */

#ifndef DOCTOR_CLASS_H_
#define DOCTOR_CLASS_H_

#include "person_class.h"


class Doctor : public Person
{
	public:
		/* Constructors */
		Doctor(Case* my_case);
		Doctor(float life, Case* my_case);
		Doctor(float life, float vaccine);
		Doctor(float life, Person::Person_state state, Case* my_case);
		Doctor(float life = 100.0, Person::Person_state state = healthy, float vaccine = 4.0, Case* my_case = new Case());

		/* Setter */
		void setVaccine(float vaccine);

		/* Getter */
		float getVaccine() const;

		/* Method */
		void heal_person(Person* p_person);
		void heal_people_in_my_case();

	private:
		/* Attribute */
		float vaccine;
};


#endif /* DOCTOR_CLASS_H_ */
