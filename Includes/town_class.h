/*
 * town_class.h
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#ifndef TOWN_CLASS_H_
#define TOWN_CLASS_H_


#include <vector>
#include <string>
#include <sstream>
#include "../Includes/case_class.h"

class Town
{
	public:
		/* Constructors */
		Town();
		Town(unsigned int height, unsigned int width);
		Town(unsigned int height, unsigned int width, std::vector< std::vector<Case*> >* p_vector_case);

		/* Setters */
		void setHeight(unsigned int height);
		void setWidth(unsigned int width);
		void setpVectorCase(std::vector<std::vector<Case*> >*& vectorCase);

		/* Getters */
		unsigned int getHeight() const;
		unsigned int getWidth() const;
		const std::vector<std::vector<Case*> >* getpVectorCase() const;

		/* Methods */
		bool init(unsigned int number_house, unsigned int number_hospital, unsigned int number_fire_station,
				  unsigned int number_total_person, unsigned int number_fireman, unsigned int number_doctor,
				  float sick_percent);

	private:
		/* Attributes */
		unsigned int height;
		unsigned int width;
		std::vector< std::vector<Case*> >* p_vector_case;

		/* Operators */
		inline friend std::ostream& operator<<(std::ostream& os, Town const& t)
		{
			std::stringstream ss;
			std::string str;
			ss << "Town " << t.getHeight() << "x" << t.getWidth() << " :\n";
			for(unsigned int i=0; i<t.getHeight(); ++i)
			{
				for(unsigned int j=0; j<t.getWidth(); ++j)
				{
					str += to_string(*((*(t.getpVectorCase()))[i][j])) + " | ";
				}
				str += '\n';
			}
			os << ss.str() << str;
			return os;
		}
};


#endif /* TOWN_CLASS_H_ */
