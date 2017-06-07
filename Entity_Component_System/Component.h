#pragma once

#include "Components.h"
#include "World.h"

// just for tagging concrete components, well, more or less...
class Component_Type
{
public:
	Component_Type(Component_Mask m) : mask(m) {};
	Component_Mask& get_mask() { return mask; }
	
private:
	Component_Mask mask;
};

// build components with this
template <typename T>
class Component : public Component_Type
{
public:

	Component() {};
	T& get()
	{
		return component_type;
	}

private:

	T component_type;
};