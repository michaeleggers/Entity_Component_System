#pragma once

//#include "Component.h"

#define MAX_ENTITIES 1024

/* Bitmasks to determine what components the entity has */
enum Component_Mask
{
	COMPONENT_NONE = 0,
	COMPONENT_VELOCITY = 1 << 0,
	COMPONENT_POSITION_2D = 1 << 1
};

typedef struct velocity
{
	velocity() : v(0.0) {};
	double v;
};

typedef struct position2D
{
	position2D() {};
	double x;
	double y;
} ;