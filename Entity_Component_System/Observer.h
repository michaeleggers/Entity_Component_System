#pragma once

#include <vector>

class Observer
{
public:

	//virtual void update() = 0;
	virtual int get_component_mask() = 0;
	virtual void add_entity(unsigned int) = 0;


};