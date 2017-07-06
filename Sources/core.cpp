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
#include "../Includes/Model/simulation_class.h"

using namespace std;


int main(int argc, char** argv)
{
	/* Create town for test */
	/* Height x Width */
	Town town_1(2, 2);

	/* Number house, number hospital, number fire station, total number of person, number of fireman, number of doctor, percentage of infected people */
	town_1.init(0, 0, 1, 10, 4, 0, 10);

	/* Create simulation */
	Simulation simu_1(&town_1);

	/* Test */
	cout << simu_1.getActualRound() << endl;
	cout << *(simu_1.getVectorTownEachRound()[simu_1.getActualRound()]) << endl;
	for(unsigned int i=0; i<10; ++i)
	{
		simu_1.next_round();
	}
	cout << simu_1.getActualRound() << endl;
	cout << *(simu_1.getVectorTownEachRound()[simu_1.getActualRound()]) << endl;

	/* End of main */
	cout << "end of main." << endl;
	return 0;
}
