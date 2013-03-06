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
	// They're then removed from the list
	trainerHeadNode->trainer->assignMember(member);
	// And they become busy
	trainerHeadNode->trainer->setStatus("busy");
	// The head node then becomes the next node
	trainerHeadNode = toDelete->link;
	// And the original head node is deleted
	delete toDelete;
}

/**
 * Removes the head element from a linked list of Member objects. Currently doesn't support
 * removing the first X amount of members, so the function has to be called in a loop elsewhere.
 * Assigns the member to a trainer by calling removeTrainerElement()
 */
void LinkedList::removeMemberElement(){
	memberNode * toDelete = memberHeadNode;
	// When a member is removed from the list, they become assigned to a trainer
	popMember = memberHeadNode->member;
	// The head node then becomes the next node
	memberHeadNode = toDelete->link;
	// And the original node is deleted
	delete toDelete;
}

/**
 * Returns the amount of items currently inside the linked list. Essentially used for testing.
 *
 * @param type the type of queue to list
 * @return nodeCount the number of nodes in the queue
 */
int LinkedList::listElements(string type){
	// nodeCount tracks the amount of nodes in the queue
	int nodeCount = 0;
	// If the type is member, the member queue is specified
	if(type == "member"){
		// Create a pointer to the head node in the member queue
		memberNode * pMemberNode = memberHeadNode;
		// Count through all the nodes in the queue
		for (pMemberNode = memberHeadNode; pMemberNode != NULL; pMemberNode = pMemberNode->link){
			nodeCount++; // Increment the node count every time you reach a new node
		}
	} else {
		// Same concept as above
		trainerNode * pTrainNode = trainerHeadNode;
		for (pTrainNode = trainerHeadNode; pTrainNode != NULL; pTrainNode = pTrainNode->link){
			nodeCount++;
		}
	}
	return nodeCount; // Return nodeCount the number of nodes in the queue
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
 * Retrieves the head node from the member list and returns it to the main functions.
 *
 * @return popMember the pointer to the member
 */
Member * LinkedList::popMemberFunc(){
	return popMember;
}
