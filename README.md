# Entity_Component_System
prototype of an ECS in C++.

***Overview:***

this prototype is based on this article: https://www.gamedev.net/resources/_/technical/game-programming/implementing-component-entity-systems-r3382

The main goal was to address the problem that the systems do not need to iterate over ALL the entities and check if they have
the necessary components required at runtime. So at this version, whenever an entity gets a new component attached the Manager
calls all the Systems and if the system has the corresponding component mask the entity ID will get saved at the system.
It uses the observer-pattern whereas the Subject is the Manager and the Observers are the Systems.


Problems so far: Only because the Systems know the entity IDs they have to work on they do not know about the Components yet. I tried to use
a templated Component class but it got me into the jungle. Still, I think this is the right way to go.
