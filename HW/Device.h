#pragma once

#include <string>

using std::string;

enum DeviceType { PHONE, PC, LAPTOP, TABLET };

#define UbuntuOS "UbuntuLinux"
#define RedHatOS "RedHatLinux"
#define MacOS "MacOS"
#define IOS "IOS"
#define WINDOWS7 "Windows7"
#define WINDOWS10 "Windows10"
#define WINDOWS11 "Windows11"
#define ANDROID "Android"

class Device 
{
private:
	DeviceType type;
	string os;
	unsigned int id;
	bool active;

public:
	void init(unsigned int id, DeviceType type, const string os);
	DeviceType getType() const;
	string getOS() const;
	unsigned int getID() const;
	bool isActive() const;
	void activate();
	void deactivate();
};