#include "pch.h"
#include "IOHandler.h"


IOHandler::IOHandler()
{
	std::vector <serial::PortInfo> devices = serial::list_ports();
	std::vector <serial::PortInfo>::iterator iter = devices.begin();

	while (iter != devices.end())
	{
		serial::PortInfo device = *iter++;
		std::string port = device.port.c_str();

		try 
		{
			mySerial = new serial::Serial(port, 9600, serial::Timeout::simpleTimeout(250));

			if (mySerial->isOpen())
			{
				// std::cout << "Connection success: " << port << std::endl
				connect = true;
				break;
			}
		}
		catch (std::exception e) {} // this line might break everything, i hope it doesn't
	}
}


IOHandler::~IOHandler()
{
}

void IOHandler::close()
{
	mySerial->flush();
	mySerial->close();
}