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
#include "../Includes/count_object_class.h"


class Case;
class Person : public CountedObject<Person>
{
	public:
		/* Enumerate */
		enum Person_state {healthy, sick, dead};

		/* Constructors */
		Person(Case* my_case);
		Person(float life, Case* my_case);
		Person(float life = 100.0, Person_state state = healthy, Case* my_case = new Case());

		/* Setters */
		void setId(unsigned int ID);
		void setLife(float life);
		void setState(Person_state state);
		void setMyCase(Case* my_case);

		/* Getters */
		unsigned int getId() const;
		float getLife() const;
		Person_state getState() const;
		Case* getMyCase() const;

		/* Method */
		bool is_alive() const;

	private:
		/* Attributes */
		unsigned int ID;
		float life;
		Person_state state;
		Case* my_case;

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
