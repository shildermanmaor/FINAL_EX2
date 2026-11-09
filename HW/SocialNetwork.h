#pragma once

#include "ProfileList.h"

using std::string;

class SocialNetwork 
{
private:
	string networkName;
	ProfileList profiles;
	unsigned int minAge;

public:
	void init(const string networkName, unsigned int minAge);
	void clear();
	string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile);
	string getWindowsDevices();
};