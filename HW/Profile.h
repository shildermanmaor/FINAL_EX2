#pragma once

#include "User.h"
#include "Page.h"
#include "UserList.h"

using std::string;

class Profile 
{
private:
	User owner;
	Page page;
	UserList friends;

public:
	void init(User owner);
	void clear();
	User getOwner() const;
	string getPage() const;
	string getFriends();
	void setStatus(string status);
	void addPostToProfilePage(string post);
	void addFriend(User newFriend);
	string getFriendsWithSameNameLength();
	void changeAllWordsInStatus(string word);
	void changeWordInStatus(string wordToReplace, string newWord);
};