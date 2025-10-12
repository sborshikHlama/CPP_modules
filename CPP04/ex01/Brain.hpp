// Implement a Brain class. It contains an array of 100 std::string called ideas.
// This way, Dog and Cat will have a private Brain* attribute.
// Upon construction, Dog and Cat will create their Brain using new Brain();
// Upon destruction, Dog and Cat will delete their Brain.

#pragma once
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
};