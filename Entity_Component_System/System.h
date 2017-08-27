#pragma once

#include <vector>
#include <iostream>

#include "Observer.h"
#include "Subject.h"
#include "Components.h"

class System : public Observer
{

public:
	System(int component_mask, Manager& manager) : component_mask_(component_mask), entities_({}), manager_(manager)
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
			os << "Entity ID: " << entity << std::endl;
			os << "position: " << rhs.manager_.pos2d[entity].x << ", " << rhs.manager_.pos2d[entity].y << std::endl;
		}
		
		return os;
	}

	void update()
	{
		for (auto& entity : entities_)
		{
			
			// update components
			manager_.pos2d[entity].x += manager_.v[entity].v;
			manager_.pos2d[entity].y += manager_.v[entity].v;
		}
	}

private:

	int component_mask_;
	std::vector<unsigned int> entities_;
	Manager& manager_;
	// reference list to registered component-lists of world
	//std::vector<Component_Type*> components;
};
