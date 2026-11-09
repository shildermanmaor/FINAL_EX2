#include "UserList.h"

void UserNode::init(User user) {
	this->data = user;
	this->next = nullptr;
}

User &UserNode::getData() {
	return data;
}

UserNode *UserNode::getNext() {
	return next;
}

void UserNode::setData(User data) {
	this->data = data;
}

void UserNode::setNext(UserNode *next) {
	this->next = next;
}

void UserList::init() {
	first = nullptr;
}

void UserList::clear() {
	UserNode *tmp;

	while (first != nullptr) {
		tmp = first;
		first = first->getNext();

		delete tmp;
	}
}

UserNode *UserList::getFirst() {
	return first;
}

void UserList::setFirst(UserNode *first) {
	this->first = first;
}

bool UserList::add(User user) {
	UserNode *node = new UserNode;
	node->init(user);

	if (first == nullptr)
		first = node;
	else {
		UserNode *tmp = first;

		while (tmp->getNext() != nullptr)
			tmp = tmp->getNext();

		tmp->setNext(node);
	}

	return true;
}
