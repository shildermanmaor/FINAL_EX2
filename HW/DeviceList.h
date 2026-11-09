#pragma once

#include "Device.h"

class DeviceNode {
private:
	Device data;
	DeviceNode *next;
public:
	void init(Device device);
	Device &get_data();
	DeviceNode *get_next();
	void setData(Device device);
	void setNext(DeviceNode *next);
};

class DevicesList {
private:
	DeviceNode *first;
public:
	void init();
	void clear();
	DeviceNode *get_first() const;
	void setFirst(DeviceNode *first);
	void add(Device device);
};