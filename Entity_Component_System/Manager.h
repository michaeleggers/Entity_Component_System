#pragma once

#include <vector>
#include <algorithm>

#include "Subject.h"
#include "Observer.h"
#include "Components.h"




/* Implementation of the Observer-Patterns Subject */
class Manager : public Subject
{
public:
	Manager() : systems({}) {};

	// add a system
	void register_observer(Observer* o)
	{
		systems.push_back(o);
	}

	// remove a system
	void remove_observer(Observer* o)
	{
		// to be implemented
		return;
	}


	unsigned int create_entity()
	{
		unsigned int entity;
		for (entity = 0; entity < MAX_ENTITIES; ++entity)
		{
			if (mask[entity] == COMPONENT_NONE)
			{
				return entity;
			}
		}
		// no more space for more entities.
		return MAX_ENTITIES;
	}

	void add_velocity(unsigned int entity, velocity& vel)
	{
		// add velocity component
		mask[entity] |= COMPONENT_VELOCITY;
		v[entity] = vel;

		// add the entity to the relevant system
		notify_systems(entity);
	}

	void add_position2D(unsigned int entity, position2D& pos2D)
	{
		// add position2D component
		mask[entity] |= COMPONENT_POSITION_2D;
		pos2d[entity] = pos2D;

		// add the entity to the relevant system
		notify_systems(entity);
	}

	//void add_component(unsigned int entity, Component_Type& component)
	//{
	//	int mask = component.get_mask();
	//	world.mask[entity] |= mask;
	//	if (mask == COMPONENT_POSITION_2D)
	//	{
	//		world.pos2d[entity] = component;
	//	}
	//	else if (mask == COMPONENT_VELOCITY)
	//	{
	//		world.velocity[entity] = component;
	//	}
	//	notify_systems(entity);
	//}

	// some components
	velocity v[MAX_ENTITIES] = {};
	position2D pos2d[MAX_ENTITIES] = {};

private:

	// index = entity, entry = component-mask
	int mask[MAX_ENTITIES] = { COMPONENT_NONE };


	std::vector<Observer*> systems;

	// call this whenever an entity gets an component added or removed.
	void notify_systems(unsigned int entity)
	{
		for (auto& system : systems)
		{
			// get systems component mask
			int component_mask = system->get_component_mask();
			// check if applicable
			if (mask[entity] & component_mask == component_mask)
			{
				system->add_entity(entity);
			}
		}
	}
};
