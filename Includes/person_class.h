/*
 * person_class.h
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#ifndef PERSON_CLASS_H_
#define PERSON_CLASS_H_


#include <iostream>

class Person
{
	public:
		/* Enumerate */
		enum Person_state {healthy, sick, dead};

		/* Constructors */
		Person();
		Person(float life);
		Person(float life, Person_state state);

		/* Setters */
		void setLife(float life);
		void setState(Person_state state);

		/* Getters */
		float getLife() const;
		Person_state getState() const;

	private:
		/* Attributes */
		float life;
		Person_state state;

		/* Operators */
		inline friend std::ostream& operator<<(std::ostream& os, Person const& p)
		{
			os << "Person : " << p.getLife() << " hp, " << p.getState();
			return os;
		}

		inline friend std::ostream& operator<<(std::ostream& os, Person_state const& p)
		{
			switch(p)
			{
				case healthy:
					os << "healthy";
					break;
				case sick:
					os << "sick";
					break;
				case dead:
					os << "dead";
					break;
			}
			return os;
		}
};


#endif /* PERSON_CLASS_H_ */
