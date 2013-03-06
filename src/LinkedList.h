#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>		// For inputs and outputs
#include "Member.h"		// For member objects
#include "Trainer.h"	// For trainer objects

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

	Member * popMember;						// The member removed from the head

public:
	LinkedList();
	virtual ~LinkedList();
	void removeTrainerElement(Member *);	// Remove a trainer from the list
	void removeMemberElement();				// Remove a member from the list
	void addTrainerElement(Trainer *);		// Add a trainer to the list
	void addMemberElement(Member *);		// Add a member to the list
	int listElements(string);				// Return the elements in the list
	void serveMembers();					// Assigns members to trainers
	bool isEmpty();							// Checks if the queues are empty
	Member * popMemberFunc();					// Returns popMember to other classes
};

#endif
