#pragma once
#include "serial/serial.h"
#include <string>
#include <vector>
#include <iterator>

class IOHandler
{
public:
	IOHandler();
	~IOHandler();

	bool connect = false;

	std::string update();

	void close();

private:
	serial::Serial* mySerial;
};

