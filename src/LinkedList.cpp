#include "LinkedList.h"

LinkedList::LinkedList() {
	// When a list is created, there is no first node
	trainerHeadNode = NULL;
	memberHeadNode = NULL;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

/**
 * Allows the addition of a Trainer object to the linked list and links the previous last element
 * to the new one being added.
 *
 * @param trainer the Trainer object
 */
void LinkedList::addTrainerElement(Trainer * trainer){
	trainerNode * newTrainerNode = new trainerNode;
	newTrainerNode->trainer = trainer;
	newTrainerNode->link = NULL;
	if(trainerHeadNode == NULL){
		// If no nodes exist, create the first node
		trainerHeadNode = newTrainerNode;
	} else {
		// Move to the end of the list
		trainerNode * newHeadNode = trainerHeadNode;
		while(newHeadNode->link != NULL){
			newHeadNode = newHeadNode->link;
		}
		// Add the new node
		newHeadNode->link = newTrainerNode;
	}
}

/**
 * Allows the addition of a Member object to the linked list and links the previous last element
 * to the new one being added.
 *
 * @param member the Member object
 */
void LinkedList::addMemberElement(Member * member){
	memberNode * newMemberNode = new memberNode;
	newMemberNode->member = member;
	newMemberNode->link = NULL;
	if(memberHeadNode == NULL){
		// If no nodes exist, create the first node
		memberHeadNode = newMemberNode;
	} else {
		// Move to the end of the list
		memberNode * newHeadNode = memberHeadNode;
		while(newHeadNode->link != NULL){
			newHeadNode = newHeadNode->link;
		}
		// Add the new node
		newHeadNode->link = newMemberNode;
	}
}

/**
 * Removes the head element from a linked list of Trainer objects. Currently doesn't support
 * removing the first X amount of trainers, so the function has to be called in a loop elsewhere.
 */
void LinkedList::removeTrainerElement(){
	trainerNode * toDelete = trainerHeadNode;
	trainerHeadNode = toDelete->link;
	delete trainerHeadNode;
}

/**
 * Removes the head element from a linked list of Member objects. Currently doesn't support
 * removing the first X amount of member, so the function has to be called in a loop elsewhere.
 */
void LinkedList::removeMemberElement(){
	memberNode * toDelete = memberHeadNode;
	memberHeadNode = toDelete->link;
	delete memberHeadNode;
}

/**
 * Returns the amount of items currently inside the linked list. Essentially used for testing.
 */
string LinkedList::listElements(){
	trainerNode * currentNode = trainerHeadNode;
	stringstream elements; // Stringstream to store number of nodes
	int nodeCount = 0;
	// While there are still links to continuing nodes
	while(currentNode != NULL){
		// Add the node to the count
		nodeCount++;
		// Move to the next node
		currentNode = currentNode->link ;
	}
	elements << nodeCount;	// Add the number of nodes to the stringstream
	return elements.str();	// Return the number of nodes as a printable string
}
