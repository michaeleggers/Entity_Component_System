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
	System(int cm, World& w) : world(w), component_mask(cm), entities({})
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
		return component_mask;
	}

	void add_entity(unsigned int entity)
	{
		entities.push_back(entity);
	}

	friend std::ostream& operator<<(std::ostream& os, System& rhs)
	{
		os << "system has the following entities: " << std::endl;
		for (unsigned int entity : rhs.entities)
		{
			os << entity << std::endl;
		}
		
		return os;
	}

	// update all entities, troublesome part. Required a lot of refactoring, because only because
	// we know the entity ID, we did not have access to the necessary component arrays.
	// So I added this vector storing all the component types this system needs.
	//void update()
	//{
	//	for (auto& entity : entities)
	//	{
	//		for (Component_Type* component : components)
	//		{
	//			component
	//		}

	//	}
	//}

private:

	World& world;
	int component_mask;
	std::vector<unsigned int> entities;
	// reference list to registered component-lists of world
	//std::vector<Component_Type*> components;
};
