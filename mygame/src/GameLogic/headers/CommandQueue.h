#pragma once

#include <queue>
#include "Command.h"

class CommandQueue {
public:
	std::queue<Command> Queue;
};