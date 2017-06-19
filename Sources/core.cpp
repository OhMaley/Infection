/*
 * core.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/case_class.h"
#include "../Includes/person_class.h"
#include "../Includes/town_class.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	/* Create town for test */
	Town town_1(3, 3);

	/* Tests */
	cout << town_1.init(1, 1, 1, 20, 4, 1, 20) << endl;
	cout << town_1 << endl;

	/* End of main */
	cout << "end of main." << endl;
	return 0;
}
