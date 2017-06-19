/*
 * case_class.h
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#ifndef CASE_CLASS_H_
#define CASE_CLASS_H_

#include <vector>
#include <sstream>

class Person;
class Case
{
	public:
		/* Enumerate */
		enum Case_type {field, house, hospital, fire_station};
		enum Case_max_people {field_max_people = 4, house_max_people = 8, hospital_max_people = 12, fire_satation_max_people = 6};

		/* Constructors */
		Case();
		Case(Case_type type);
		Case(Case_type type, unsigned int nb_person, std::vector<Person*> vector_person);

		/* Setters */
		void setNbPersonMax(unsigned int nb_person_max);
		void setType(Case_type type);
		void setVectorPerson(const std::vector<Person*>& vector_person);

		/* Getters */
		unsigned int getNbPersonMax() const;
		Case_type getType() const;
		const std::vector<Person*>& getVectorPerson() const;

	private:
		/* Attributes */
		Case_type type;
		unsigned int nb_person_max;
		std::vector<Person*> vector_person;

		/* Operators */
		inline friend std::ostream& operator<<(std::ostream& os, Case const& c)
		{
			os << "Case : " << c.getType() << ", " << c.getNbPersonMax() << " people max, occupied by " << c.getVectorPerson().size() << " people";
			return os;
		}

		inline friend std::ostream& operator<<(std::ostream& os, Case_type const& c)
		{
			switch(c)
			{
				case field:
					os << "field";
					break;
				case house:
					os << "house";
					break;
				case hospital:
					os << "hospital";
					break;
				case fire_station:
					os << "fire station";
					break;
			}
			return os;
		}

		friend std::string to_string(const Case& c)
		{
			std::ostringstream ss;
			ss << c;
			return ss.str();
		}
};


#endif /* CASE_CLASS_H_ */
