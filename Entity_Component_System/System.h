#pragma once

#include <vector>
#include <iostream>

#include "Observer.h"
#include "Subject.h"
#include "World.h"
#include "Component.h"

class System : public Observer
{

public:
	System(int component_mask) : component_mask_(component_mask), entities_({})
	{
		//// store references to all relevant component lists
		//if (COMPONENT_POSITION_2D & component_mask == COMPONENT_POSITION_2D)
		//{
		//	components.push_back((world.pos2d));
		//}
		//if (COMPONENT_VELOCITY & component_mask == COMPONENT_VELOCITY)
		//{
		//	components.push_back((world.velocity));
		//}
	}

	int get_component_mask()
	{
		return component_mask_;
	}

	void add_entity(unsigned int entity)
	{
		entities_.push_back(entity);
	}

	friend std::ostream& operator<<(std::ostream& os, System& rhs)
	{
		os << "system has the following entities: " << std::endl;
		for (unsigned int entity : rhs.entities_)
		{
			os << entity << std::endl;
		}
		
		return os;
	}

	/* Only because we know the entity IDs relevant to this system we do not have 
	   access to the required components. We should save a reference to these. */
	//void update()
	//{
	//	for (auto& entity : entities)
	//	{
	//		
	//		// update components
	//	}
	//}

private:

	int component_mask_;
	std::vector<unsigned int> entities_;
	// reference list to registered component-lists of world
	//std::vector<Component_Type*> components;
};
