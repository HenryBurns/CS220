#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

template <class T>
class NODE {
	public:
	T data;
	NODE<T>* next = nullptr;
    NODE<T>();
	};
template <class T>
NODE<T>::NODE(){}
template <class T>
class LLC{
	private:
	NODE<T>* first;
	NODE<T>* last;
	public:
        int length = 0;
	NODE<T>* getFirst();
	NODE<T>* getLast();
	LLC();
	LLC(LLC const &);
	~LLC();
	bool contains(const T &);
	bool insert(const T &);
        NODE<T>* getElement();
        void addNode(NODE<T>*);
        T getData(int indx);
	void remove(const T &);
	void shuffle();
	void head(int n);
	int len();
        void clear();
	void join(LLC &other);
	T tail();
	LLC& operator+=(int n);
	LLC& operator=(const LLC &);
	LLC operator+(const LLC &);
	//TODO include templating for friend function.
	template <class U>
	friend std::ostream& operator<<(std::ostream &, const LLC<U>&);
};
	template <class T>
	LLC<T>::LLC(){
		first = nullptr;
		last = nullptr;
	}
//work
	template <class T>
	LLC<T>::LLC(LLC<T> const &other){
		first = nullptr;
		last = nullptr;
		NODE<T>* other_temp = other.first;
		NODE<T>* prev = nullptr;
		while(other_temp != NULL){
			NODE<T>* temp_node = new NODE<T>;
			if(prev != nullptr)
				prev->next = temp_node;
			if(first == nullptr)
				first = temp_node;
			temp_node ->data = other_temp -> data;
			prev = temp_node;
			last = temp_node;
			other_temp = other_temp -> next;
		}
	}

	template <class T>
        void LLC<T>::clear(){
            NODE<T>* temp = first;
            while(temp != NULL){
                        temp = temp->next;
                        delete first;
                        first = temp;
                }
            last = nullptr;
            first = nullptr;
        }

	template <class T>
    NODE<T>* LLC<T>::getElement(){
            NODE<T>* temp = first;
            first = first -> next;
            length--;
            if(temp == last){
                    first = nullptr;
                    last = nullptr;
            }
            return temp;
    }

	template <class T>
    T LLC<T>::getData(int indx){
            NODE<T>* temp = first;
            for(int i = 0;i < indx; i++)
                    temp = temp->next;
            return temp->data;
    }
	template <class T>
    void LLC<T>::addNode(NODE<T>* input){
        if(input == nullptr){
            std::cout << "THIS SHIT IS EMPTY WTF\n\n\n\n" << std::endl;
            return;
        }
        length++;
        input->next = NULL;
        if(last != nullptr){
            last->next = input;
            last = input;
        }
        else{
                first = input;
                last = input;
        }
    }

	template <class T>
	LLC<T>::~LLC(){
		NODE<T>* temp = first;
		while(temp != nullptr){
			first = temp ->next;
			delete(temp);
			temp = first;
		}
	}
//works
	template <class T>
	bool LLC<T>::contains(const T &val){
		NODE<T>* temp = first;
		while(temp != nullptr){
			if(temp->data == val)
				return true;
			temp = temp -> next;
		}
		return false;
	}
//works
	template <class T>
	bool LLC<T>::insert(const T &value){
		NODE<T>* temp = new NODE<T>;
                if(first == nullptr)
                        first = temp;
		if(last == nullptr){
			first = temp;
			last = temp;
		}
		else{
			last -> next = temp;
			last = last->next;
		}
		temp -> data = value;	
                length++;
		return true;
	}
//works
	template <class T>
	void LLC<T>::remove(const T &value){
		if(first == nullptr)
			return;
		NODE<T>* temp = first;
		while(temp != nullptr && first -> data == value){
			first = first -> next;
			delete(temp);
			temp = first;
		}
		NODE<T>* prev = temp;
		if(temp != nullptr){
			temp = temp -> next;
			while(temp != nullptr){
				if(temp -> data == value){
					prev -> next = temp -> next;
					delete temp;
				}
				else{
					prev = temp;
				}
				temp = prev -> next;
			}
		}
		last = prev;
                length--;
	}
//TODO
	template <class T>
	void LLC<T>::shuffle(){
		//generate a random seed
		//srand(time(0));
		//create a random number of times to switch elements
		int n = (rand()%40),rand1, rand2;
		//get the length of the list
		int length = len();
		//declare temporary pointers
		NODE<T>* temp,*temp2,*temp3, *rand1_prev, *rand2_prev;
		for(int i = 0; i < n; i++){
			//get 2 random node indexes to switch
			rand1 = (rand()%(length))+1;
			rand2 = (rand()%(length))+1;
			//if rand1 = rand2 do nothing
			if(rand1 != rand2){
				temp = first;
				for(int i = 1; i < std::max(rand1,rand2); i++){
					if(i == rand1 -1)
							rand1_prev = temp;
					if(i == rand2-1)
							rand2_prev = temp;
					temp = temp -> next;
				}
				if(rand1 == 1){
						if(rand2 == 2){
							temp = first;
							temp2 = rand2_prev->next->next;
							first = rand2_prev->next;
							first->next = temp;
							temp->next = temp2;
						}
						else{
							temp = first;
							temp2 = rand2_prev->next->next;
							first = rand2_prev->next;
							first->next = temp->next;
							rand2_prev->next=temp;
							temp->next = temp2;
						}
				}	
				else if(rand2 == 1){
						if(rand1 == 2){
							temp = first;
							temp2 = rand1_prev->next->next;
							first = rand1_prev->next;
							first->next = temp;
							temp->next = temp2;
						}
						else{
						temp = first;
						temp2 = rand1_prev->next->next;
						first = rand1_prev->next;
						first->next = temp->next;
						rand1_prev->next=temp;
						temp->next = temp2;

						}
				}
				else if(rand1 > rand2){
					//goodbye -> next = hello -> next
					if(rand2_prev->next == rand1_prev){
						temp = rand1_prev->next->next;
						temp2 = rand1_prev->next;
						temp3 = rand2_prev->next;
						rand2_prev->next = temp2;
						temp2->next = temp3;
						temp3->next = temp;
					}
					else{

					temp = rand1_prev->next->next;
					temp2 = rand2_prev->next->next;
					//save the continuation of the list
					temp3 = rand1_prev->next;
					//save the node to be replaced
					rand1_prev->next = rand2_prev->next;
					rand1_prev->next->next = temp;
					rand2_prev->next = temp3;
					temp3->next = temp2;
					}
				}
				else if(rand1 < rand2){
					if(rand1_prev->next == rand2_prev){
						temp = rand2_prev->next->next;
						if(temp != nullptr)
						temp2 = rand2_prev->next;
						temp3 = rand1_prev->next;
						rand1_prev->next = temp2;
						temp2->next = temp3;
						temp3 ->next = temp;
					}
					else{
						temp = rand2_prev->next->next;
						temp2 = rand1_prev->next->next;
						rand2_prev->next->next = temp2;
						rand1_prev->next->next = temp;
						temp = rand2_prev->next;
						rand2_prev->next = rand1_prev->next;
						rand1_prev->next = temp;
					}
				}
			}
		}
		temp = first;
		while(temp != nullptr){
				temp2 = temp;
				temp = temp->next;
	}
	last = temp2;
}

//works
	template <class T>
	void LLC<T>::head(int n){
		NODE<T>* temp = first;
		std::cout << "[";
		for(int i = 0; i < n-1; i++){
			if(temp == nullptr){
				std::cout << "NULL]\n";
				return;
			}
			else{
				std::cout<< temp->data << ", ";
				temp = temp->next;
			}
		}
		std::cout << temp->data << "]\n";
		return;
	}

	template <class T>
	T LLC<T>::tail(){
	std::cout << last->data << std::endl;
	return last ->data;
	}

//works 
	template <class T>
	void LLC<T>::join(LLC<T> &other){
		NODE<T>* temp = other.first;
		if(temp != nullptr){
			while(temp != nullptr){
				NODE<T>* new_node = new NODE<T>;
				new_node->data = temp ->data;
				last ->next = new_node;
				last = new_node;
				temp = temp-> next;
			}
			last->next = nullptr;
		}
		else{
			std::cout << "Other was null" << std::endl;
		}
		return;
}
//works
	template <class T>
	int LLC<T>::len(){
                if(first != nullptr){
		    NODE<T>* temp = first;
		    int cntr = 1;
		    while(temp != last){
			temp = temp -> next;
			cntr++;
    		    }
    		return cntr;
                }
                return 0;
	}
//works
	template <class T>
	LLC<T>& LLC<T>::operator=(const LLC<T>& other){
		if(this != &other){
			NODE<T>* iter = first;
			NODE<T>* thing;
				while(iter != nullptr){
						thing = iter->next;
						delete(iter);
						iter = thing;
				}
				iter = other.first;
				NODE<T>* temp = new NODE<T>; 
				first = temp;
				if(iter == nullptr)
					first = nullptr;
				while(iter != nullptr){
					temp->data = iter-> data;
					last = temp;
					temp = new NODE<T>; 
					last->next = temp;
					iter = iter-> next;
				}
				delete temp;
				last ->next = nullptr;
		}
		return *this;
	}
//works
	template <class T>
	std::ostream& operator<<(std::ostream &os, const LLC<T>& to_print){
		NODE<T>* temp = to_print.first;
		os << "[";
		if(temp == nullptr)
				os << "NULL]";
		while(temp != nullptr){
			if(temp->next !=nullptr)
				os << temp->data << ", ";
			else
				os << temp->data << "]";
			temp = temp->next;
			}
		return os;
	}
//works
	template <class T>
	LLC<T> LLC<T>::operator+(const LLC<T> &other){
		LLC<T> new_llc1 = LLC();
		LLC<T>* new_llc = &new_llc1;
		new_llc->last = nullptr;
		NODE<T>* temp = this->first;
		while(temp != nullptr){
				NODE<T>* next = new NODE<T>;
				if(new_llc->last == nullptr){
						next->data = temp -> data;
						new_llc->last = next;
						new_llc->first = next;
						temp = temp->next;
				}
				else {
					new_llc->last->next = next;
					next ->data = temp->data;
					temp = temp->next;
					new_llc->last = new_llc->last->next;
				}
		}
		temp = other.first;
		while(temp != nullptr){
                                length++;
				NODE<T>* next = new NODE<T>;
				if(new_llc->last == nullptr){
						new_llc->last = next;
						new_llc->first = next;
						next = temp->next;
				}
				else {
					new_llc->last->next = next;
					next ->data = temp->data;
					temp = temp->next;
					new_llc->last = new_llc->last->next;
				}
		}
		last->next = nullptr;
                std::cout << "List after joining: ";
		new_llc->head(new_llc->len());
		return new_llc1;
	}

//works
	template <class T>
	LLC<T>& LLC<T>::operator+=(int n){
		int length = len();
		n = n%length;
		for(int i = 0; i < n; i++){
			last -> next = first;
			last = last -> next;
			first = first->next;
			last -> next = nullptr;
		}	
		return *this;
	}

	template <class T>
	NODE<T>* LLC<T>::getFirst(){
			return first;
	}
	template <class T>
	NODE<T>* LLC<T>::getLast(){
			return last;
	}
#endif
