/*
 * person_class.h
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#ifndef PERSON_CLASS_H_
#define PERSON_CLASS_H_

#include <iostream>
#include <string>
#include <sstream>
#include "../Includes/case_class.h"

class Case;
class Person
{
	public:
		/* Enumerate */
		enum Person_state {healthy, sick, dead};

		/* Constructors */
		Person();
		Person(float life);
		Person(Case* p_my_case);
		Person(float life, Person_state state);
		Person(float life, Case* p_my_case);
		Person(float life, Person_state state, Case* p_my_case);

		/* Public attribute */
		Case* p_my_case;

		/* Setters */
		void setLife(float life);
		void setState(Person_state state);
		void setMyCase(Case*& myCase);

		/* Getters */
		float getLife() const;
		Person_state getState() const;
		Case*& getMyCase() const;

		/* Method */
		bool is_alive() const;

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

		friend std::string to_string(Person_state const& p)
		{
			std::ostringstream ss;
			ss << p;
			return ss.str();
		}
};


#endif /* PERSON_CLASS_H_ */
