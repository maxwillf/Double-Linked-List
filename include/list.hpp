#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator> //for std::distance

namespace ls
{

	template <typename T>
	class list{
		private:
		struct Node {
			T data;
			Node *prev;
			Node *next;
			Node(const T & d = T () , Node *p = nullptr, Node *n = nullptr): data (d),prev (p), next (n) {}
			Node( T d = T () , Node *p = nullptr, Node *n = nullptr):data (d),prev (p), next (n){}
		};
		
		int m_size;
		Node *m_head;
		Node *m_tail;

		public:

		list( std::initializer_list<T> ilist );
		
		class const_iterator{
			public:
			const_iterator( );
			const T & operator * ( ) const;
			const_iterator & operator ++ ( );// ++it;
			const_iterator operator ++ ( int ); // it++;
			const_iterator & operator -- ( ); // --it;
			const_iterator operator -- ( int ); // it--;
			bool operator == ( const const_iterator & rhs ) const;
			bool operator != ( const const_iterator & rhs ) const;
			
			protected :
			Node *current;
			const_iterator( Node * p ) : current( p ){}
			friend class list<T>;
			
		};


		class iterator : public const_iterator{
			public :
			iterator( ) : const_iterator() { }
			const T & operator * ( ) const;
			T & operator * ( );
		
			iterator & operator++ ();
			iterator operator++ (int);
			iterator & operator-- ();
			iterator operator-- (int);
		
			protected :
			iterator( Node *p ) : const_iterator( p ){}
			friend class list<T>;
		};

		// [I] SPECIAL MEMBERS

		/*! \brief Default constructor */
	
		list(void);

		/*! \brief Default destructor */
	
		~list( );
	
		/*! \brief */

		list( const list & );
	
		/*! \brief */
			
		list & operator = ( const list & );
		 
		// [II] ITERATORS
			
		/*! \brief Returns a iterator that points to the beginning of the list
		 * \return Iterator to the beginning of the list 
	 	*/

		iterator begin();
				
		/*! \brief Returns a constant iterator that points to the beginning of the list
	 	* \return Constant iterator to the beginning of the list
	 	*/

		const_iterator cbegin( ) const;
				
		/*! \brief Returns a iterator that points to the end of list
	 	* \return Iterator to the end of list
	 	*/			
		
		iterator end( );

		/*! \brief Returns a constant iterator to the end of list
	 	* \return Constant iterator to the end of list
	 	*/

		const_iterator cend( ) const;
				
		// [III] Capacity 
				
		/*! \brief Returns the number of elements in the list
		 * \return Logical size of list
 	 	 */
			
		int size( ) const;

		/*! \brief Verifies if the list is empty
	 	 * \return True if is the list empty, else returns False
	 	 */		
		
		bool empty( ) const;
			
		// [IV] Modifiers
		
		/*! \brief Clear the list
		 */
		
		void clear( );

		/*! \brief Returns a reference to the first element of the list
	 	 * \return The value of the first element of the list
	  	 */					

		T & front( );
			
		/*! \brief Returns a constant reference to the first element of the list
		 * \return The value of the first element of the list
		 */	
			
		const T & front( ) const;
				
		/*! \brief Returns a reference to the last element of the list
		 * \return The value of the last element of the list
	 	 */
		
		T & back( );
	
		/*! \brief Returns a constant reference to the last element of the list 
		 * \return The value of the last element of the list
		 */		

		const T & back( ) const;
				
		void push_front( const T & value );
					
		void push_back( const T & value );
		
		void pop_front( );
				
		void pop_back( );
				
		void assign(const T& value );
			
		// [IV-a] Modifiers with iterators

		template < class InItr >

		void assign( InItr first, InItr last );

		void assign( std::initializer_list<T> ilist );

		iterator insert( const_iterator itr, const T & value );

		iterator insert( const_iterator pos, std::initializer_list<T> ilist );

		iterator erase( const_iterator itr );

		iterator erase( const_iterator first, const_iterator last );

		const_iterator find( const T & value ) const;
		
};



}

#include "list.inl"
#endif
