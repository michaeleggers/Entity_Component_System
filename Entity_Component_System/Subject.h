#pragma once

#include "Observer.h"

/* Interface for Subject in Observer-Pattern */
class Subject
{
public:

	virtual void register_observer(Observer*) = 0;
	virtual void remove_observer(Observer*) = 0;
};