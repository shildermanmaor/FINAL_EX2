#pragma once

#include "Profile.h"

class ProfileNode 
{
private:
	Profile data;
	ProfileNode *next;

public:
	void init(Profile profile);
	Profile &getData();
	ProfileNode *getNext();
	void setData(Profile profile);
	void setNext(ProfileNode *next);
};

class ProfileList {
private:
	ProfileNode *first;
public:
	void init();
	void clear();
	ProfileNode *getFirst();
	void setFirst(ProfileNode *first);
	bool add(Profile profile);
};

