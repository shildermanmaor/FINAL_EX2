#pragma once

#include "User.h"

class UserNode 
{
private:
	User data;
	UserNode *next;

public:
	void init(User user);
	User &getData();
	UserNode *getNext();
	void setData(User new_user);
	void setNext(UserNode *next);
};

class UserList {
private:
	UserNode *first;
public:
	void init();
	void clear();
	UserNode *getFirst();
	void setFirst(UserNode *first);
	bool add(User user);
};