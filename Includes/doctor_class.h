/*
 * doctor_class.h
 *
 *  Created on: 19 juin 2017
 *      Author: trmary
 */

#ifndef DOCTOR_CLASS_H_
#define DOCTOR_CLASS_H_

#include "../Includes/person_class.h"


class Doctor : public Person
{
	public:
		/* Constructors */
		Doctor();
		Doctor(float life);
		Doctor(float life, Person::Person_state state);
		Doctor(float life, float vaccine);
		Doctor(float life, Person::Person_state state, float vaccine);

		/* Setter */
		void setVaccine(float vaccine);

		/* Getter */
		float getVaccine() const;

		/* Method */
		void heal(Person* p_person);

	private:
		/* Attribute */
		float vaccine;
};


#endif /* DOCTOR_CLASS_H_ */
