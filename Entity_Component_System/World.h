#pragma once

#include "Components.h"
//#include "Component.h"

#define MAX_ENTITIES 1024

/* Bitmasks to determine what components the entity has */
enum Component_Mask
{
	COMPONENT_NONE = 0,
	COMPONENT_VELOCITY = 1 << 0,
	COMPONENT_POSITION_2D = 1 << 1
};

class World
{
public:
	World() {};
	// index = entity, entry = component-mask
	int mask[MAX_ENTITIES] = { COMPONENT_NONE };

	// some components
	velocity v[MAX_ENTITIES] = {};
	position2D pos2d[MAX_ENTITIES] = {};
};