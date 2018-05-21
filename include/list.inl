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

	// [II] ITERATORS - DONE
	
	/* Returns a iterator to the beginning of the list */
	template <class T>
	typename list<T>::iterator list<T>::begin(){
		return list<T>::iterator(m_head);
	}
		
	/* Returns a constant iterator to the beginning of the list */
	template <class T>
	typename list<T>::const_iterator list<T>::cbegin() const{
		return list<T>::const_iterator(m_head->next);
	}
	
	/* Returns a iterator to the end of the list */
	template <class T>
	typename list<T>::iterator list<T>::end(){
		return list<T>::iterator(m_tail);
	}

	/* Returns a constant iterator to the end of the list */
	template <class T>
	typename list<T>::const_iterator list<T>::cend() const{
		return list<T>::const_iterator(m_tail);
}
	// [III] CAPACITY - DONE

	/* Return the number of elements in the list */
	template <class T>
	int list<T>::size() const {
		return m_size;
	}

	/* Check if is the list empty */
	template <class T>
	bool list<T>::empty() const {
		return (m_head->next == m_tail and m_tail->prev == m_head);
	}
	
	// [IV] MODIFIERS 	

	/* Clear the list */
	template <class T>
	void list<T>::clear(){
		auto it(begin());
	}	

	/* Returns a reference to the first element of the list */	
	template <class T>
	T & list<T>::front(){
		if(empty())
			throw std::out_of_range("The list is empty!");
		return m_head->next->data;
	}

	/* Returns a constant reference to the first element of the list */
	template <class T>
	const T & list<T>::front() const{
		if(empty())
			throw std::out_of_range("The list is empty!");
		return m_head->next->data;
	}

	/* Returns a reference to the last element of the list */
	template <class T>	
	T & back(){
		if(empty())
			throw std::out_of_range("The list is empty!");
		return m_head->prev->data;
	}

	
	/* Returns a constant reference to the last element of the list */
	template <class T>
	const T & back() const{
		if(empty())
			throw std::out_of_range("The list is empty!");
		return m_head->prev->data;
	}

	/* Insert a element in the beggining of list */
	template <class T>	
	void push_front( const T & value ){
	}

	/* Insert a element at the end of list */
	template <class T>
	void push_back( const T & value ){
	}
			
	/* Remove a element at the beginning of list */
	template <class T>	
	void pop_front( ){
	}
		
	/* Remove a element at end of list */
	template <class T>	
	void pop_back( ){
	}
			
	template <class T>	
	void assign(const T& value ){
	}
	
