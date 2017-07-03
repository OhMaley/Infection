/*
 * count_object_class.h
 *
 *  Created on: 23 juin 2017
 *      Author: Tristan
 */

#ifndef COUNT_OBJECT_CLASS_H_
#define COUNT_OBJECT_CLASS_H_


template <typename T>
class CountedObject
{
	public:
		/* Constructor */
		CountedObject()
		{
			++total_instance_created;
			++number_actual_instance;
		}
		CountedObject(CountedObject const&)
		{
			++total_instance_created;
			++number_actual_instance;
		}

		/* Destructor */
		virtual ~CountedObject()
		{
			--number_actual_instance;
		}

		/* Method */
		static unsigned int Count_actual_instance()
		{
			return number_actual_instance;
		}

		static unsigned int Count_total_instance()
		{
			return total_instance_created;
		}

	private:
		static unsigned int total_instance_created;
		static unsigned int number_actual_instance;
};

template <typename T>
unsigned int CountedObject<T>::number_actual_instance = 0;

template <typename T>
unsigned int CountedObject<T>::total_instance_created = 0;

#endif /* COUNT_OBJECT_CLASS_H_ */
