#include "DeviceList.h"

void DeviceNode::init(Device device) 
{
	data = device;
	next = nullptr;
}

Device &DeviceNode::get_data() 
{
	return data;
}

DeviceNode *DeviceNode::get_next() 
{
	return next;
}

void DeviceNode::setData(Device device) 
{
	this->data = device;
}

void DeviceNode::setNext(DeviceNode *next) 
{
	this->next = next;
}

void DevicesList::init() 
{
	first = nullptr;
}

void DevicesList::clear() 
{
	DeviceNode *tmp;

	while (first != nullptr) 
	{
		tmp = first;
		first = first->get_next();

		delete tmp;
	}
}

DeviceNode *DevicesList::get_first() const 
{
	return first;
}

void DevicesList::setFirst(DeviceNode *first) 
{
	this->first = first;
}

void DevicesList::add(Device device) 
{
	DeviceNode *node = new DeviceNode;
	node->init(device);

	if (first == nullptr)
		first = node;
	else {
		DeviceNode *tmp = first;

		while (tmp->get_next() != nullptr)
			tmp = tmp->get_next();

		tmp->setNext(node);
	}
}