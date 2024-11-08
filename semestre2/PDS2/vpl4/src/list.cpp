#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
    if (!this->head) {
        cout << "Lista vazia!";
        return;
    }
    
    if (this->head == this->tail){
        return;
    }

    Node* current = this->head;
    Node* previous = nullptr;
    Node* next = nullptr;

    this->tail = this->head;

    while (current != nullptr) {
        next = current->next; 
        current->next = previous; 
        previous = current; 
        current = next; 
    }

    this->head = previous;
}
