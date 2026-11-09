#pragma once

#include <string>

using std::string;

class Page 
{
private:
	string status;
	string posts;

public:
	void init();
	void clearPage();
	string getStatus() const;
	string getPosts() const;
	void setStatus(const string status);
	void addLineToPosts(const string line);
};