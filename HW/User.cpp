#include "User.h"

void User::init(unsigned int id, const string username, unsigned int age) 
{
	this->id = id;
	this->username = username;
	this->devices.init();
	this->age = age;
}

void User::clear() 
{
	id = 0;
	username = "";
	devices.clear();
	age = 0;
}

unsigned int User::getID() const 
{
	return id;
}

string User::getUserName() const 
{
	return username;
}

unsigned int User::getAge() const 
{
	return age;
}

DevicesList &User::getDevices() 
{
	return devices;
}

void User::addDevice(Device newDevice) 
{
	devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const 
{
	DeviceNode *tmp = devices.get_first();

	while (tmp != nullptr) 
	{
		if (!tmp->get_data().isActive())
			return false;

		tmp = tmp->get_next();
	}

	return true;
}