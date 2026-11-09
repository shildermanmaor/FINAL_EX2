#include "Page.h"

void Page::init() 
{
	status = "";
	posts = "";
}

void Page::clearPage() 
{
	posts = "";
}

string Page::getStatus() const 
{
	return status;
}

string Page::getPosts() const 
{
	return posts;
}

void Page::setStatus(const string status) 
{
	this->status = status;
}

void Page::addLineToPosts(const string line) 
{
	posts += line + '\n';
}