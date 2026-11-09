#pragma once

#include <string>

#include "DeviceList.h"

using  std::string;

class User 
{
private:
	unsigned int id;
	string username;
	DevicesList devices;
	unsigned int age;

public:
	void init(unsigned int id, const string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	string getUserName() const;
	unsigned int getAge() const;
	DevicesList &getDevices();
	void addDevice(Device device);
	bool checkIfDevicesAreOn() const;
};