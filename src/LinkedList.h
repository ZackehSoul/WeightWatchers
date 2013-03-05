#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <sstream>
#include "Member.h"
#include "Trainer.h"

using namespace std;

class LinkedList {
private:

	// Information stored in a trainer node
	class trainerNode{
	public:
		Trainer * trainer;	// Pointer to the trainer object
		trainerNode * link;	// Link to the next node in the list
	} * trainerHeadNode;	// Pointer to the first node

	// Information stored in a member node
	class memberNode{
	public:
		Member * member;	// Pointer to the member object
		memberNode * link;	// Link to the next node in the list
	} * memberHeadNode;		// Pointer to the first node

public:
	LinkedList();
	virtual ~LinkedList();
	void removeTrainerElement();		// Remove a trainer from the list
	void removeMemberElement();			// Remove a member from the list
	void addTrainerElement(Trainer *);	// Add a trainer to the list
	void addMemberElement(Member *);	// Add a member to the list
	string listElements();				// Return the elements in the list
};

#endif
