#include "SocialNetwork.h"

void SocialNetwork::init(const string networkName, unsigned int minAge) 
{
	this->networkName = networkName;
	profiles.init();
	this->minAge = minAge;
}

void SocialNetwork::clear() 
{
	networkName = "";
	profiles.clear();
	minAge = 0;
}

string SocialNetwork::getNetworkName() const 
{
	return networkName;
}

int SocialNetwork::getMinAge() const 
{
	return minAge;
}

bool SocialNetwork::addProfile(Profile profile) 
{
	if (profile.getOwner().getAge() < minAge)
		return false;

	profiles.add(profile);

	return true;
}

string SocialNetwork::getWindowsDevices() 
{
	ProfileNode *tmpProfile = profiles.getFirst();
	string devices = "";

	while (tmpProfile != nullptr) 
	{
		DeviceNode *tmpDevice = tmpProfile->getData().getOwner().getDevices().get_first();

		while (tmpDevice != nullptr) 
		{
			string os = tmpDevice->get_data().getOS();

			if (os == WINDOWS7 || os == WINDOWS10 || os == WINDOWS11) 
			{
				string tmpData = '[' + std::to_string(tmpDevice->get_data().getID()) + ", " + os + ']';

				if (devices == "")
					devices = tmpData;
				else
					devices += ", " + tmpData;
			}

			tmpDevice = tmpDevice->get_next();
		}

		tmpProfile = tmpProfile->getNext();
	}

	return devices;
}