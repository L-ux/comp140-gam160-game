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

	void close();

private:
	serial::Serial* mySerial;
};

