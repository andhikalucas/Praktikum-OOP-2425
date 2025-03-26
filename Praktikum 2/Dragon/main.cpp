#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon d("Draco");  // A creature has been born! A dragon has been born!
    d.speak(); // I am the mighty dragon Draco! Beware of my flames!
    d.wound(); // Additional Health -10
    d.wound(); // Additional Health -10
    d.print(); // Base Health: 100; Additional Health: 80
    d.speak(); // I am the mighty dragon Draco! Beware of my flames!

    Creature *d2 = &d;
    d2->wound(); // Health -10
    d2->print(); // Base Health: 90
    
    d.print(); // Base Health: 90; Additional Health: 80

    Creature d3 = d;
    d3.speak(); // I am a mystical creature named Draco!
    d3.wound(); // Base Health - 10
    d3.print(); // Base Health: 80
    d.print(); // Base Health: 90; Additional Health: 80
    return 0;
}

/*
A creature has been born!
A dragon has been born!
I am the mighty dragon Draco! Beware of my flames!
Base Health: 100; Additional Health: 80
I am the mighty dragon Draco! Beware of my flames!
Base Health: 90
Base Health: 90; Additional Health: 80
I am a mystical creature named Draco!
Base Health: 80
Base Health: 90; Additional Health: 80
*/