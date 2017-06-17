/*
 * town_class.cpp
 *
 *  Created on: 17 juin 2017
 *      Author: Tristan
 */

#include "../Includes/town_class.h"

/* Constructors */
Town::Town()
{
	this->height = 10;
	this->width = 10;
	this->p_vector_case = new std::vector< std::vector<Case*> >();
	this->p_vector_case->resize(this->height, std::vector<Case*>(this->width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(*(this->p_vector_case))[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width)
{
	this->height = height;
	this->width = width;
	this->p_vector_case = new std::vector< std::vector<Case*> >();
	this->p_vector_case->resize(height, std::vector<Case*>(width, new Case()));
	for(unsigned int i=0; i<height; ++i)
	{
		for(unsigned int j=0; j<width; ++j)
		{
			(*(this->p_vector_case))[i][j] = new Case();
		}
	}
}

Town::Town(unsigned int height, unsigned int width, std::vector <std::vector<Case*> >* p_vector_case)
{
	this->height = height;
	this->width = width;
	this->p_vector_case = p_vector_case;
}

/* Setters */
void Town::setHeight(unsigned int height)
{
	this->height = height;
}

void Town::setWidth(unsigned int width)
{
	this->width = width;
}

void Town::setpVectorCase(std::vector<std::vector<Case*> >*& p_vectorCase)
{
	p_vector_case = p_vectorCase;
}

/* Getters */
unsigned int Town::getHeight() const
{
	return height;
}

unsigned int Town::getWidth() const
{
	return width;
}

const std::vector<std::vector<Case*> >* Town::getpVectorCase() const
{
	return p_vector_case;
}
