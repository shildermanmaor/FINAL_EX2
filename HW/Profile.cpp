#include <algorithm>
#include <cctype>

#include "Profile.h"

void Profile::init(User owner) 
{
	page.init();
	friends.init();
	this->owner.init(owner.getID(), owner.getUserName(), owner.getAge());

	DeviceNode *tmp = owner.getDevices().get_first();
	while (tmp != nullptr) 
	{
		this->owner.addDevice(tmp->get_data());
		tmp = tmp->get_next();
	}
}

void Profile::clear() 
{
	owner.clear();
	page.clearPage();
	friends.clear();
}

User Profile::getOwner() const 
{
	return owner;
}

string Profile::getPage() const 
{
	string page = "Status: " + this->page.getStatus();
	page += "\n*******************\n*******************\n";
	page += this->page.getPosts();

	return page;
}

string Profile::getFriends() 
{
	UserNode *tmp = friends.getFirst();
	string friends = "";

	while (tmp != nullptr) 
	{
		if (friends.empty())
			friends = tmp->getData().getUserName();
		else
			friends += ',' + tmp->getData().getUserName();

		tmp = tmp->getNext();
	}

	return friends;
}

void Profile::setStatus(string status) 
{
	page.setStatus(status);
}

void Profile::addPostToProfilePage(string post) 
{
	page.addLineToPosts(post);
}

void Profile::addFriend(User newFriend) 
{
	friends.add(newFriend);
}

string Profile::getFriendsWithSameNameLength() 
{
	UserNode *tmp = friends.getFirst();
	string friends = "";

	while (tmp != nullptr) 
	{
		string username = tmp->getData().getUserName();

		if (username.length() == owner.getUserName().length()) 
		{
			if (friends == "")
				friends = username;
			else
				friends += ',' + username;
		}

		tmp = tmp->getNext();
	}

	return friends;
}

void Profile::changeAllWordsInStatus(string word) 
{
	string status = page.getStatus();
	string result = "";
	bool newWord = true;

	for (int i = 0; i < status.length(); i++) 
	{
		if (std::isspace(( unsigned char ) status[i])) 
		{
			result += status[i];
			newWord = true;
		}
		else if (newWord) 
		{
			result += word;
			newWord = false;
		}
	}

	page.setStatus(result);
}

void Profile::changeWordInStatus(string wordToReplace, string newWord) 
{
	string status = page.getStatus();
	string result = "";
	size_t wordPosition = 0;
	size_t prevPosition = 0;

	while ((wordPosition = status.find(wordToReplace, prevPosition)) != string::npos) 
	{
		result += status.substr(prevPosition, wordPosition - prevPosition);
		result += newWord;

		prevPosition = wordPosition + wordToReplace.length();
	}

	result += status.substr(prevPosition, status.length() - prevPosition);

	page.setStatus(result);
}