#pragma once
#ifndef LISTA_H
#define LISTA_H

#include <cstddef>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;
template <typename T> class Node {
private:
  T data;
  Node<T> *next;
  Node<T> *previous;
  template <typename U> friend class LinkedList;

public:
  Node(T data, Node<T> *next, Node<T> *previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
  } //Constructor del Node complejidad es: O(1)
};

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *last;
  int _size;

public:
  LinkedList() {
    head = last = NULL;
    _size = 0;
  } //Constructor del LinkedList complejidad es: O(1)

/* Método para agregar un nodo al inicio de la lista. Con complejidad es: O(1) */
  void addFirst(T dato) {
    _size++; // O(1)
    // SORT the code:
    Node<T> *nuevo = new Node<T>(dato, NULL, NULL);// O(1)
    if (head == NULL && last == NULL) { // si es vacía la lista
      head = last = nuevo; // O(1)
    } else {
      nuevo->next = head; // O(1)
      head->previous = nuevo; // O(1)
      head = nuevo; // O(1)
    }
  }
/*Método imprime todos los nodos de la lista.Con complejifas O(n)*/
  void print() {
    Node<T> *aux = head; // O(1)
    while (aux != NULL) { // O(n)
      cout << aux->data << endl; // O(1)
      aux = aux->next; // O(1)
    }
  }
/* Método imprime todos los nodos de la lista pero reverse. Complejidad de O(n) */
  void reverse() {
    Node<T> *aux = last; // O(1)
    while (aux != NULL) { // O(n)
      cout << aux->data << endl; // O(1)
      aux = aux->previous; // O(1)
    }
  }

/* Método que regresa 1, si la lista no tiene elementos. */
  bool is_empty() { return (head == NULL) ? true : false; } // O(1)

/*Método para agregar un nodo al final de la lista. Complejidad O(1) */
  void addLast(T dato) {
    _size++; // O(1)
    Node<T> *nuevo = new Node<T>(dato, NULL, NULL); // O(1)
    if (is_empty()) { // O(1)
      head = last = nuevo; // addFirst(dato)
    } else {
      last->next = nuevo; // O(1)
      nuevo->previous = last; // O(1)
      last = nuevo; // O(1)
    }
  }
  /*Construstor de la clase LinkedList para el size del inicial Complejidad O(1)*/
  LinkedList(int size) : LinkedList(){
    for (int i = 0; i < size; i++) //O(1)
    {
      T dato; //O(1)
      addLast(dato); //O(1)
    }
  }
  
  /* Método para calcular el tamaño de la lista, cuántos elementos tenemos. Complejidad O(1) */
  int size() { return this->_size; } //O(1)

/* Método para revisar si existe un elemento, regresa 1 si existe o 0 sino existe. Complejidad O(n)*/
  bool contains(T data) {
    Node<T> *temp = head; //O(1)
    bool exists = 0; //O(1)
    while (temp != NULL && exists == 0) { //O(n)
      if (data == temp->data) { //O(1)
        exists = 1;//O(1)
      }
      temp = temp->next;//O(1)
    }
    return exists;//O(1)
  }

  /* Método para obtener un elemento que se encuentra en una posición: "index". Si index es menor a 0 o mayor al tamaño se lanza exception. Complejidad O(n) */
  T &get(int index) {
    if (index < 0 || index > size())
      throw -1;
    Node<T> *temporal = head;
    for (int i = 0; i < index; i++) {
      temporal = temporal->next;
    }
    return temporal->data;
  }

  /* Método para remover de la lista el primer elemento, si la lista NO es vacía se puede realizar. Complejidad O(n)  */
  T remove_front() {
    if (is_empty()) { //O(1)
      throw -1;//O(1)
    } else if (head == last) { //O(1)
      // 1 nodo
      T dato = head->data; // sacar dato O(1)
      delete head;         // borrar nodo O(1)
      head = last = NULL;
      _size--; //O(1)
      return dato; //O(1)
    } else {
      // minimo 2 nodos
      T dato = head->data; //O(1)
      head = head->next; //O(1)
      delete head->previous; //O(1)
      head->previous = NULL; //O(1)
      _size--; //O(1)
      return dato; //O(1)
    }
  }

  /* Método para remover de la lista el último elemento, si la lista NO es vacía se puede realizar. Complejidad O(1) */
  T remove_last() { //O(1)
    if (is_empty()) { //O(1)
      throw -1; //O(1)
    } else if (head == last) { //O(1)
      // 1 nodo
      T dato = head->data; // sacar dato
      delete head;         // borrar nodo
      head = last = NULL; //O(1)
      _size--; //O(1)
      return dato; //O(1)
    } else { //O(1)
      // minimo 2 nodos
      T dato = last->data;
      last = last->previous;
      delete last->next;
      last->next = NULL;
      _size--;
      return dato;
    }
  }

  /* Obtiene el dato guardado en el último nodo Complejidad O(1)*/
  T getFirst() { //O(1)
    if (is_empty()) { //O(1)
      throw 1; //O(1)
    }
    return head->data; //O(1)
  }

  /*Obtiene el dato guardado en el último nodo. Complejidad O(1)*/
  T getLast() { //O(1)
    if (is_empty()) { //O(1)
      throw 1;
    }
    return last->data; //O(1)
  }

  /* Método para remover de la lista el último elemento, si la lista NO es vacía se puede realizar.  */
  T remove(int index) {
    if (is_empty()) { //O(1)
      throw -1; //O(1)
    } else if (index == 0) { //O(1)
      return remove_front();
    } else if (index == _size) { //O(1)
      return remove_last(); //O(1)
    } else {
      Node<T> *aux = head;
      for (int i = 0; i < index; i++)
        aux = aux->next; //O(n-2)
      // minimo 2 nodos
      T dato = aux->data; //O(1)
      aux->previous->next = aux->next; //O(1)
      aux->next->previous = aux->previous; //O(1)
      aux->next = NULL; //O(1)
      aux->previous = NULL; //O(1)
      delete aux; //O(1)
      _size--; //O(1)
      return dato; //O(1)
    }
  }
/* Método para insertar el dato del index, -1 si la lista esta vacia o es menor a 0 >= al tamaño. Complejidad O(n2)*/
  void insert(T dato, int index) {
    if (is_empty()) { //O(1)
      throw -1; //O(1)
    } else if (index < 0 && index > _size) { //O(1)
      throw -1;
    } else {
      Node<T> *aux = head; //O(1)
      for (int i = 0; i < index; i++) //O(n2) por la iteración en el index
        aux = aux->next; //O(1)
      // minimo 2 nodos
      Node<T> *n = new Node<T>(dato, NULL, NULL); //O(1)
      n->next = aux; //O(1)
      n->previous = aux->previous; //O(1)
      aux->previous = n; //O(1)
      n->previous->next = n;//O(1)
      _size++;//O(1)
      //return dato;
    }
  }
  /*BUSCA EL ELEMENTO A BUSCAR*/
  int find(T data){
    if(!contains(data))
      throw -1;
    Node<T> *temp = head;
    int index = 0;
    while(temp != NULL){
      if(data == temp->data){
        return index;
      }
      temp = temp->next;
      index++;
    }
    return -1;
  }
  /*SOBRECARGA DEL OPERADOR*/
  T &operator[](int index){
    return get(index); //O(n)
  }
/*DESTRUCTOR de la clase LinkedList Complejidad O(n)*/
  ~LinkedList(){
    for (int i = 0; i<_size;i++){ //O(n)
      remove_last();
    }
  }
  /*SOBRECARGA DEL OPERADOR Complejidad  O(n)*/
  friend ostream &operator<<(ostream &salida, LinkedList<T> &lista){ //Función friend para conceder el acceso
    for(int i=0;i<lista.size(); i++){
      salida << lista.get(i)<<" || "<<endl;
    }
    return salida;
  }
};
#endif