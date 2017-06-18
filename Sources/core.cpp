/*
 * core.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/case_class.h"
#include "../Includes/person_class.h"
#include "../Includes/town_class.h"

using namespace std;
#include <iostream>

int main(int argc, char** argv)
{
	/* Creation of multiple Person for test */
	Person person_1;
	Person person_2(50.2);
	Person person_3(25.3, Person::sick);

	/* Creation of multiple Case for test */
	Case case_1;
	Case case_2(Case::house);
	vector<Person*> list_person_1;
	list_person_1.push_back(&person_1);
	list_person_1.push_back(&person_3);
	Case case_3(Case::hospital, Case::hospital_max_people, list_person_1);

	/* Create town for test */
	Town town_1(3, 3);
	(*(town_1.getpVectorCase()))[1][0]->setType(Case::hospital);
	(*(town_1.getpVectorCase()))[1][0]->setNbPersonMax(Case::hospital_max_people);
	(*(town_1.getpVectorCase()))[1][0]->setVectorPerson(list_person_1);

	/* Tests */
	cout << town_1 << endl;
	cout << town_1.init(1, 1, 1, 10, 1, 1, 10) << endl;

	/* End of main */
	cout << "end of main." << endl;
	return 0;
}
