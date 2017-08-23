#include <iostream>
#include <string>

#include "Manager.h"
#include "System.h"
#include "Components.h"

/*
	TODO: whenever a component gets added to an entity, all the systems have to check if it
	is relevant for them through notify_systems() in the Manager.-> The Systems probably
	should only store references to the component lists they operate on. Entities are
	rather uninteresting for them.

	Adding new Components to an Entity work through the add_XXX() functions in the Manager.
	Rather than adding Components through the Manager with a lot of different functions,
	maybe make Components templates and add them to concrete Entities, which at the
	moment are just integers.
*/


using namespace std;


int main(int argc, char** argv) {

	// test the EC-System
	Manager manager;
	int movement_mask = COMPONENT_POSITION_2D | COMPONENT_VELOCITY;
	System movement_system(movement_mask, manager); // maybe keep ref to subject to use its world reference
	manager.register_observer(&movement_system);
	unsigned int player = manager.create_entity();

	//Component<position2D> pos2d;
	//pos2d.get().x = 10.0;
	//pos2d.get().y = 20.0;
	position2D pos2d;
	pos2d.x = 10.0;
	pos2d.y = 20.0;
	velocity v;
	v.v = 9.81;

	manager.add_position2D(player, pos2d);
	// the movement-system should not print anything because the velocity component is missing
	cout << movement_system << endl;
	// now the movement-system should get the player id.
	manager.add_velocity(player, v);

	cout << movement_system << endl; // prints 0 as the player has the required components
	movement_system.update();
	cout << movement_system << endl;
	getchar();

	return 0;
}