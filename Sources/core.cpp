/*
 * core.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/case_class.h"
#include "../Includes/person_class.h"
#include "../Includes/town_class.h"
#include "../Includes/fireman_class.h"
#include "../Includes/doctor_class.h"
#include <iostream>

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
