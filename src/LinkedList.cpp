#include "LinkedList.h"
#include "WeightWatchers.h"

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
 *
 * @param member the member assigned to the trainer
 */
void LinkedList::removeTrainerElement(Member * member){
	trainerNode * toDelete = trainerHeadNode;
	// When a trainer is removed from the list, they're assigned a member
	trainerHeadNode->trainer->assignMember(member);
	// And they become busy
	trainerHeadNode->trainer->setStatus("busy");
	// They're then removed from the list
	trainerHeadNode = toDelete->link;
	delete trainerHeadNode;
}

/**
 * Removes the head element from a linked list of Member objects. Currently doesn't support
 * removing the first X amount of members, so the function has to be called in a loop elsewhere.
 * Assigns the member to a trainer by calling removeTrainerElement()
 */
void LinkedList::removeMemberElement(){
	memberNode * toDelete = memberHeadNode;
	// When a member is removed from the list, they become assigned to a trainer
	removeTrainerElement(memberHeadNode->member);
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

/**
 * Determines if the queues are empty, and returns true if they are.
 *
 * @return true if the queues are empty
 */
bool LinkedList::isEmpty(){
	// If nothing exists in the queue, return true
	if(trainerHeadNode == NULL && memberHeadNode == NULL){
		return true;
	} else {
		return false;
	}
}

/**
 * Tracks and assigns member objects from the start of the queue to a trainer. This only
 * occurs when both lists aren't empty.
 */
void LinkedList::serveMembers(){
	WeightWatchers * pMain = new WeightWatchers();
	// If the simulation is running, the queue is moving
	while(pMain->isSimulationRunning()){
		// If there is both a trainer and a member waiting, the member becomes assigned
		if(!pMain->memberList.isEmpty() && !pMain->trainerList.isEmpty()){
			cout << "assignment made" << endl;
			pMain->memberList.removeMemberElement();
		}
	}
	return;
}
