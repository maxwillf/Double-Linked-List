#include "list.hpp"

namespace ls
{


	template <typename T>
		list<T>::list(void){

		Node *m_head = new Node();
		Node *m_tail = new Node();
		m_head->next = m_tail;
		m_tail->prev = m_head;

		m_size = 0;
		m_head = new Node();
		m_tail = new Node();
		m_head->next = m_tail;
		m_tail->prev = m_head;
		}

	template <typename T>
		list<T>::~list(){

			Node *temp = m_head;

			while (temp->next != m_tail){

				temp = temp->next;
				if(temp->prev != m_head){
					delete temp->prev;
				}
			}

		} 
			delete m_head;
			delete m_tail;

		}

	template <typename T>
	void list<T>::push_front(const T& value)
	{
		Node *push = new Node(value,m_head,m_head->next);
		m_head->next->prev = push;
		m_head->next = push;
		std::cout << m_head->next->data << std::endl;
		std::cout << m_head->next << std::endl;
		std::cout << m_head << std::endl;
		std::cout << m_tail << std::endl;
	}

	template <class T>
	typename list<T>::iterator list<T>::begin(){
		return list<T>::iterator(m_head);
	}
	
	template <class T>
	typename list<T>::iterator list<T>::end(){
		return list<T>::iterator(m_tail);
	}
}
