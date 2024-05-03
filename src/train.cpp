// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
	first = nullptr;
	countOp = 0;
}

void Train::addCage(bool light) {
	Cage* cage;
	cage->light = light;
	cage->next = nullptr;

	if (first == nullptr) {
		cage->prev = nullptr;
		first = cage;
	} else {
		Cage* current = first;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = cage;
		cage->prev = current;
	}
	countOp++;
}

int Train::getLength() {
	int length = 0;
	Cage* current = first;
	first->light = true;
	while (true) {
		current = current->next;
		countOp++;
		length++;
		if (current->light == true) {
			current->light = false;
			while (current != first) {
				current = current->prev;
				countOp++;
			}
			if (first->light == false)
				return length;
		}
	}
}

int Train::getOpCount() {
	return countOp;
}
