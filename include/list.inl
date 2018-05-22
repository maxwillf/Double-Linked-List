#include "list.hpp"

namespace ls
{
	/* Default constructor */
	template <typename T>
		list<T>::list(void){

			m_size = 0;
			m_head = new Node();
			m_tail = new Node();
			m_head->next = m_tail;
			m_tail->prev = m_head;
		}

	template <typename T>
		list<T>::~list(){

			Node *temp = m_head;
			while (temp != m_tail){
				temp = temp->next;
				if(temp->prev != m_head){
					delete temp->prev;
				}
			}

			delete m_head;
			delete m_tail;

		}

	/* Insert a element in the beggining of list */
	template <typename T>
		void list<T>::push_front(const T& value){
			Node *push = new Node(value,m_head,m_head->next);
			m_head->next->prev = push;
			m_head->next = push;
			m_size++;
		}
	/* Insert a element at the end of list */
		template <typename T>
		void list<T>::push_back( const T & value ){

			Node *push = new Node(value,m_tail->prev,m_tail);
			m_tail->prev->next = push;
			m_tail->prev = push;
			m_size++;
		}
	// [II] ITERATORS - DONE

	/* Returns a iterator to the beginning of the list */
	template <typename T>
		typename ls::list<T>::iterator ls::list<T>::begin(){
			return ls::list<T>::iterator(m_head->next);
		}

	/* Returns a constant iterator to the beginning of the list */
	template <typename T>
		typename ls::list<T>::const_iterator ls::list<T>::cbegin() const{
			return ls::list<T>::const_iterator(m_head->next);
		}

	/* Returns a iterator to the end of the list */
	template <typename T>
		typename ls::list<T>::iterator ls::list<T>::end(){
			return ls::list<T>::iterator(m_tail);
		}

	/* Returns a constant iterator to the end of the list */
	template <typename T>
		typename ls::list<T>::const_iterator ls::list<T>::cend() const{
			return ls::list<T>::const_iterator(m_tail);
		}

	// [III] CAPACITY - DONE

	/* Return the number of elements in the list */
	template <typename T>
		int list<T>::size() const {
			return m_size;
		}

	/* Check if is the list empty */
	template <typename T>
		bool list<T>::empty() const {
			return (m_head->next == m_tail and m_tail->prev == m_head);
		}

	// [IV] MODIFIERS 	
	/* Clear the list */
	template <typename T>
		void list<T>::clear(){
			auto it(begin());
			while(it++ != end()){
				erase(ls::list<T>::iterator(it.data->prev));
			}
		}	

	/* Returns a reference to the first element of the list */	
	template <typename T>
		T & list<T>::front(){
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_head->next->data;
		}

	/* Returns a constant reference to the first element of the list */
	template <typename T>
		const T & list<T>::front() const{
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_head->next->data;
		}

	/* Returns a reference to the last element of the list */
	template <typename T>	
		T & list<T>::back(){
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_head->prev->data;
		}


	/* Returns a constant reference to the last element of the list */
	template <typename T>
		const T & list<T>::back() const{
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_tail->prev->data;
		}
	/*! Inserts value before itr position
	 * @params itr
	 * @params value
	 * @return iterator to inserted value position
	 * */
	template <typename T>
	typename list<T>::iterator list<T>::insert
	(typename list<T>::const_iterator itr, const T & value ){

		typename list<T>::Node* inserted =
			new typename list<T>::Node(value,itr.current->prev,itr.current);
		m_size++;
		itr.current->prev->next = inserted;
		itr.current->prev = inserted;
		return inserted;
	}
	
	/*! Inserts the initializer_list's elements before itr position
	 * @params itr
	 * @params ilist
	 * @return iterator to inserted values position
	 * */
	template <typename T>
	typename list<T>::iterator list<T>::insert( const_iterator pos, std::initializer_list<T> ilist ){
			
			list<T>::iterator itr;
			for (auto i = ilist.begin(); i < ilist.end(); ++i) {
				 itr = list<T>::insert(pos,*i);	
			}

			int size = ilist.size();
			return itr-size;
		}

	/*! Inserts the elements in the [first,last) range before itr position
	 * @params itr
	 * @params first
	 * @params last
	 * @return iterator to inserted values position
	 * */
	template <typename T>
	template <typename InItr>	
	typename list<T>::iterator list<T>::insert(iterator pos, InItr first, InItr last){

		for (auto i = first; i != last; ++i) {
			list<T>::insert(pos,*i);	
		}
		return pos-(last-first);
	}


	/* Remove a element at the beginning of list */
	template <typename T>	
		void pop_front( ){
		}

	/* Remove a element at end of list */
	template <typename T>	
		void pop_back( ){
		}

	template <typename T>	
		void assign(const T& value ){
		}

	/*! Iterator operators */
	template <typename T>
	T & list<T>::iterator::operator * ( ){
		return this->current->data;
	}
	
	/*! Iterator operator ++ */
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator ++( ){
		this->current = this->current->next;
		return *this;
	}
	
	/*! Iterator operator -- */
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator --( ){
		this->current = this->current->prev;
		return *this;
	}
	
	/*! Iterator operator -- */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator --(int ){
		auto copy = *this;
		this->current = this->current->prev;
		
		return copy;
	}
	/*! Iterator operator ++ */
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator ++(int ){
		auto copy = *this;
		this->current = this->current->next;
		
		return copy;
	}

	template <typename T>
		bool list<T>::const_iterator::operator != ( const const_iterator & rhs ) const{

	//		std::cout << "lhs  " << this->current << std::endl;
	//		std::cout << "rhs  " << rhs.current << std::endl;
			return this->current != rhs.current;
	}
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator+ (int a){

		for (int i = 0; i < a; ++i) {
			
			if (this->current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			this->current = this->current->next;
			
		}
		return *this;
	}
	/*! Iterator - operand*/	
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator- (int a){

		for (int i = 0; i < a; ++i) {
			
			if (this->current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			this->current = this->current->prev;
			
		}
		return *this;
	}
	
	/*! Const_Iterator - operand*/	
	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator- (int a){

		for (int i = 0; i < a; ++i) {
			
			if (this->current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			this->current = this->current->prev;
			
		}
		return *this;
	}
	template <typename T>
	std::ptrdiff_t list<T>::iterator::operator- (list<T>::iterator rhs){
		return this->current - rhs.current;
	}

}
