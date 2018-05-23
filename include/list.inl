#include "list.hpp"

namespace ls
{

	// I SPECIAL MEMBERS

	/*! @brief Default constructor */
	
	template <typename T>
		list<T>::list(void){

			m_size = 0;
			m_head = new Node();
			m_tail = new Node();
			m_head->next = m_tail;
			m_tail->prev = m_head;
		}

	/*! @brief Constructor with the content of a initializer list
	 *  @param ilist Initializer list who will fill the list		
	 */
	
	template <typename T>
		list<T>::list( std::initializer_list<T> ilist ): list<T>::list(){

			insert(begin(),ilist.begin(),ilist.end());
		}

	/*! @brief Copy constructor
	 *  @param other A list to be copied
	 */
	
	template <typename T>
		list<T>::list( const list<T> & other ): list<T>::list(){
			*this = other;
		} 
	
	/*! @brief Copy assigment operator
	 *  @param other A list to be copied
	 *  @return The new object
	 */
	
	template <typename T>
		list<T>& list<T>::operator= ( const list<T> & other ){

			
			assign(other.cbegin(),other.cend());

			return *this;	
		}
	
	/* @brief Default destructor
	 */

	template <typename T>
		list<T>::~list(){
			if(m_size != 0) clear();

	 		delete m_head;
			delete m_tail;

		}

	// [II] ITERATORS 

	/*! @brief Returns a iterator to the beginning of the list 
	 *  @return Iterator who points to the beginning of the list
	 */

	template <typename T>
		typename ls::list<T>::iterator ls::list<T>::begin(){
			return ls::list<T>::iterator(m_head->next);
		}

	/*! @brief Returns a constant iterator to the beginning of the list 
	 *	@return Constant iterator who points to the beginning of the list
	 */

	template <typename T>
			typename ls::list<T>::const_iterator ls::list<T>::cbegin() const{
			return ls::list<T>::const_iterator(m_head->next);
		}

	/*! @brief Returns a iterator to the end of the list
	 *	@return Iterator who points to the end of the list
	 */

	template <typename T>
		typename ls::list<T>::iterator ls::list<T>::end(){
			return ls::list<T>::iterator(m_tail);
		}

	/*! @brief Returns a constant iterator to the end of the list
	 *	@return Constant iterator who points to the end of the list
	 */

	template <typename T>
		typename ls::list<T>::const_iterator ls::list<T>::cend() const{
			return ls::list<T>::const_iterator(m_tail);
		}

	/*! @brief Returns a reference to the object in the position who iterator points
	 *	@return The value who iterator points
	 */

	template <typename T>		
	const T & list<T>::const_iterator::operator * ( ) const{
		return this->current->data;
	}
	
	
	/*! @brief Increase the iterator to the next position in list (++it)
	 *	@return The iterator
	 */

	template <typename T>		
	typename list<T>::const_iterator & list<T>::const_iterator::operator ++ ( ){// ++it;
	
		this->current = this->current->next;
		return *this;
	}
	
	/*! @brief Increase the iterator to the next position in list (it++)
	 *	@return The iterator
	 */

	template <typename T>		
	typename list<T>::const_iterator list<T>::const_iterator::operator ++ ( int ){ // it++;
	
		auto copy = *this;	
		this->current = this->current->next;
		return *copy;
	}

	/*! @brief Decrease the iterator to the prev position in list (--it)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::const_iterator list<T>::const_iterator::operator --(int ){
		auto copy = *this;
		this->current = this->current->prev;

		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return copy;
	}
	
	/*! @brief Decrease the iterator to the prev position in list (it--)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator --( ){
		this->current = this->current->prev;

		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return *this;
	}

	// [III] CAPACITY - DONE

	/*! @brief Return the number of elements in the list
	 *	@return The number of elements in the list	
	 */

	template <typename T>
		int list<T>::size() const {
			return m_size;
		}

	/*! @brief Check if is the list empty 
	 *	@return Return true if the list is empty, else return false
	 */

	template <typename T>
		bool list<T>::empty() const {
			return (m_head->next == m_tail and m_tail->prev == m_head);
		}

	// [IV] MODIFIERS 

	/*! @brief Clear the list */

	template <typename T>
		void list<T>::clear(){
			
			erase(begin(),end());
			m_size = 0;
		}	

	/*! @brief Returns a reference to the first element of the list 
	 *	@return The value of first element in the list
	 */	

	template <typename T>
		T & list<T>::front(){
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_head->next->data;
		}

	/*! @brief Returns a constant reference to the first element of the list 
	 *	@return The value of first element in the list
	 */	

	template <typename T>
		const T & list<T>::front() const{
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_head->next->data;
		}

	/*! @brief Returns a reference to the last element of the list 
	 *	@return The value of last element in the list
	 */		

	template <typename T>	
		T & list<T>::back(){
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_tail->prev->data;
		}

	/*! @brief Returns a constant reference to the last element of the list 
	 *	@return The value of last element in the list
	 */

	template <typename T>
		const T & list<T>::back() const{
			if(empty())
				throw std::out_of_range("The list is empty!");
			return m_tail->prev->data;
		}

	/*! @brief Inserts value before itr position
	 * 	@params itr
	 * 	@params value
	 * 	@return iterator to inserted value position
	 */

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
	
	/*! @briefInserts the initializer_list's elements before itr position
	 * 	@params itr
	 * 	@params ilist
	 * 	@return iterator to inserted values position
	 */

	template <typename T>
	typename list<T>::iterator list<T>::insert( const_iterator pos, std::initializer_list<T> ilist ){
			
		list<T>::iterator itr;
		for (auto i = ilist.begin(); i < ilist.end(); ++i) {
				itr = list<T>::insert(pos,*i);	
		}
		if(itr == begin()) return itr;
		int size = ilist.size();
		return itr+1-size;
	}

	/*! @brief Inserts the elements in the [first,last) range before itr position
	 * 	@params itr
	 * 	@params first
	 * 	@params last
	 * 	@return iterator to inserted values position
	 */

	template <typename T>
	template <typename InItr>	
	typename list<T>::iterator list<T>::insert(iterator pos, InItr first, InItr last){

		list<T>::iterator itr;
		int size = 0;
		for (auto i = first; i != last; ++i) {
			itr = list<T>::insert(pos,*i);	
			size++;
		}
		if(itr == begin()) return itr;
		return itr+1-size;
	}

	/*! @brief Insert a element in the beggining of list
	 * 	@param The value who's will be inserted
	 */

	template <typename T>
		void list<T>::push_front(const T& value){
			Node *push = new Node(value,m_head,m_head->next);
			m_head->next->prev = push;
			m_head->next = push;
			m_size++;
		}

	/*! @brief Insert a element in the end of list
	 * 	@param The value who's will be inserted
	 */

	template <typename T>
		void list<T>::push_back( const T & value ){

			Node *push = new Node(value,m_tail->prev,m_tail);
			m_tail->prev->next = push;
			m_tail->prev = push;
			m_size++;
		}

	/*! @brief Remove a element in the beggining of list
	 * 	@param The value who's will be inserted
	 */

	template <typename T>	
		void pop_front( ){
			if(empty())
				throw("pop_front() cannot remove elements from a empty list")
			erase(begin())
		}

	/*! @brief Remove a element in the end of list
	 * 	@param The value who's will be inserted
	 */
	 
	template <typename T>	
		void pop_back( ){
			if(empty())
				throw std::out_of_range("pop_back() cannot remove elements from a empty list")
			erase(ls::list<T>::iterator(m_tail->prev));
		}

	/*! @brief Replace the content of the list with the param
	 *	@param Value who's will be 
	 */

	template <typename T>	
		void assign(const T& value ){
		}

	/*! @brief Returns a reference to the object pointed by iterator
	 * 	@return The value who's iterator points
	 */

	template <typename T>
	T & list<T>::iterator::operator * ( ){
		return this->current->data;
	}
	
	/*! @brief Increase the iterator to the next position in list (++it)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator ++( ){
		this->current = this->current->next;
		return *this;
	}
	
	/*! @brief Decrease the iterator to the next position in list (--it)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator --( ){
		this->current = this->current->prev;
		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return *this;
	}
	
	/*! @brief Decrease the iterator to the next position in list (it--)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator --(int ){
		auto copy = *this;
		this->current = this->current->prev;

		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return copy;
	}

	/*! @brief Increase the iterator to the next position in list (it++)
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator ++(int ){
		auto copy = *this;
		this->current = this->current->next;
		if (this->current == nullptr){
			throw std::out_of_range("Iterator went out of bounds!");
		}
		return copy;
	}

	/*! @brief Return true if the iterators are reference to diferent parts of list
	 * 	@return Return true if the iterators are reference to diferent parts of list, else, return false
	 */

	template <typename T>
		bool list<T>::const_iterator::operator != ( const const_iterator & rhs ) const{

			return this->current != rhs.current;
	}

	/*! @brief Return true if the iterators are reference to equal parts of list
	 * 	@return Return true if the iterators are reference to equal parts of list, else, return false
	 */
	
	template <typename T>
		bool list<T>::const_iterator::operator == ( const const_iterator & rhs ) const{

			return this->current == rhs.current;
	}

	/*! @brief Increase the iterator to the next position in the list
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator+ (int a){
	
		auto copy = *this;
		for (int i = 0; i < a; ++i) {
			
			if (copy.current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			copy.current = copy.current->next;
			
		}
		return copy;
	}


	/*! @brief Increase the iterator to the prev position in the list
	 *	@return The iterator
	 */

	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator- (int a){
		
		auto copy = *this;
		for (int i = 0; i < a; ++i) {
			
			if (copy.current == nullptr){
				throw std::out_of_range("Iterator went out of bounds!");
			}
			copy.current = copy.current->prev;
			
		}
		return copy;
	}

	/*! @brief Increase the iterator to the prev position in the list
	 *	@return The iterator
	 */

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

	/*! @brief Remove a element in param "pos" position
	 *  @params pos Iterator who's point to the element to be removed
	 *  @return Iterator to the element next to pos
	 */

	template <typename T>
	 typename list<T>::iterator list<T>::erase (list<T>::const_iterator pos){
			
		auto ret = list<T>::iterator(pos.current->next); 
		 if(pos != end()){

			pos.current->next->prev = pos.current->prev;
			pos.current->prev->next = pos.current->next;
			delete pos.current;
		 }
		 m_size--;
		 return ret;
	}

	/*! @brief Remove the elements in the interval [first, last)
	 *	@param first Iterator to the first element who will be removed
	 *	@param last Iterator to the element after the last who will be removed
	 * 	@return 
	 */

	template <typename T>
	 typename list<T>::iterator list<T>::erase 
	 (list<T>::iterator first, list<T>::iterator last){
		
		 list<T>::iterator itr = erase(first);
		 while(itr != last){
			itr = erase(itr);
		 }
		return itr;
	 }

	/*! @brief Replace the content of the list with copies of the param "value"
	 * 	@param value Value who will replace the elements
	 * 	@param count The final range of process of replacement
	 */

	template <typename T>
	void list<T>::assign(int count, const T& value ){
		if(m_size != 0) list<T>::clear(); 

		for (int i = 0; i < count; ++i) {
			list<T>::insert(list<T>::begin(),value);
		}
	}

	/*! @brief Replace the content of the list with copies of elements in the range [first, last)
	 *	@param first Iterator to the first value in the range
	 *	@param last Iteratr to the element after the last value in the range
	 */
	
	template <typename T>
	template <typename InItr >
	void list<T>::assign( InItr first, InItr last ){
		if(m_size != 0) list<T>::clear(); 
		
		insert(begin(),first,last);
	} 

	/*! @brief Replace the content of the list with a initializer list
	 *	@param ilist The inizializer list who will replace the elements of the list
	 */

	template <typename T>
	void list<T>::assign( std::initializer_list<T> ilist ){

		if(m_size != 0) list<T>::clear(); 

		insert(begin(),ilist.begin(),ilist.end());
	}

}
