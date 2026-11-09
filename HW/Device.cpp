#include "Device.h"

void Device::init(unsigned int id, DeviceType type, const string os) 
{
	this->type = type;
	this->os = os;
	this->id = id;
	active = true;
}

DeviceType Device::getType() const 
{
	return type;
}

string Device::getOS() const 
{
	return os;
}

unsigned int Device::getID() const 
{
	return id;
}

bool Device::isActive() const 
{
	return active;
}

void Device::activate() 
{
	active = true;
}

void Device::deactivate() 
{
	active = false;
}