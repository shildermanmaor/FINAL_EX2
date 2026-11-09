#include "ProfileList.h"

void ProfileNode::init(Profile profile) {
	data = profile;
	next = nullptr;
}

Profile &ProfileNode::getData() {
	return data;
}

ProfileNode *ProfileNode::getNext() {
	return next;
}

void ProfileNode::setData(const Profile profile) {
	this->data = profile;
}

void ProfileNode::setNext(ProfileNode *next) {
	this->next = next;
}

void ProfileList::init() {
	first = nullptr;
}

void ProfileList::clear() {
	ProfileNode *tmp;

	while (first != nullptr) {
		tmp = first;
		first = first->getNext();

		delete tmp;
	}
}

ProfileNode *ProfileList::getFirst() {
	return first;
}

void ProfileList::setFirst(ProfileNode *first) {
	this->first = first;
}

bool ProfileList::add(const Profile profile) {
	ProfileNode *node = new ProfileNode;
	node->init(profile);

	if (first == nullptr)
		first = node;
	else {
		ProfileNode *tmp = first;

		while (tmp->getNext() != nullptr)
			tmp = tmp->getNext();

		tmp->setNext(node);
	}

	return true;
}
