#include "list.hpp"

namespace ls
{


	template <typename T>
		list<T>::list(void){

		Node *m_head = new Node();
		Node *m_tail = new Node();
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
}
