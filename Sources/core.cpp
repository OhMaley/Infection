/*
 * core.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include <iostream>
#include "../Includes/Model/case_class.h"
#include "../Includes/Model/doctor_class.h"
#include "../Includes/Model/fireman_class.h"
#include "../Includes/Model/person_class.h"
#include "../Includes/Model/town_class.h"

using namespace std;


int main(int argc, char** argv)
{
	/* Create town for test */
	/* Height x Width */
	Town town_1(10, 10);

	/* Tests */
	/* Number house, number hospital, number fire station, total number of person, number of fireman, number of doctor, percentage of infected people */
	town_1.init(1, 1, 1, 27, 4, 2, 20);
	cout << town_1 << endl;

	/* End of main */
	cout << "end of main." << endl;
	return 0;
}
