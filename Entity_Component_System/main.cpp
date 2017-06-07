#include <iostream>
#include <string>

#include "Manager.h"
#include "World.h"
#include "System.h"
#include "Components.h"

using namespace std;


int main(int argc, char** argv) {



	// test the EC-System
	World world;
	Manager manager(world);
	int movement_mask = COMPONENT_POSITION_2D | COMPONENT_VELOCITY;
	System movement_system(movement_mask, world); // maybe keep ref to subject to use its world reference
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

	cout << movement_system << endl;

	manager.add_velocity(player, v);

	cout << movement_system << endl;
	getchar();

	return 0;
}