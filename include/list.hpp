#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator> //for std::distance

/*!
 * @file 	list.hpp
 * @author 	Felipe Andrade and Max William
 */


using size_type = size_t;

namespace ls
{

	template <typename T>
	class list{
		private:
		struct Node {
			T data;
			Node *prev;
			Node *next;
			Node( T d = T () , Node *p = nullptr, Node *n = nullptr):data (d),prev (p), next (n){}
		};
		
		size_type m_size;
		Node *m_head;
		Node *m_tail;

		public:

		
		class const_iterator{
			public:
			const_iterator( ) = default;
			const T & operator * ( ) const;
			const_iterator & operator ++ ( );// ++it;
			const_iterator operator ++ ( int ); // it++;
			const_iterator & operator -- ( ); // --it;
			const_iterator operator -- ( int ); // it--;
			const_iterator & operator- (int );
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
			iterator  operator+ (int);
			iterator & operator-- ();
			iterator operator-- (int);
			iterator  operator- (int );
		
			protected :
			iterator( Node *p ) : const_iterator( p ){}
			friend class list<T>;
		};

		// [I] SPECIAL MEMBERS

		list(void);

		~list( );
	
		list( std::initializer_list<T> ilist );

		explicit list(size_type count);
		
		list( const list& );
				
		list & operator = ( const list & );
		 
		// [II] ITERATORS
	
		iterator begin();
	
		const_iterator cbegin( ) const;
				
		iterator end( );
	
		const_iterator cend( ) const;
				
		// [III] Capacity 
				
		int size( ) const;
		
		bool empty( ) const;
			
		// [IV] Modifiers
		
		void clear( );

		T & front( );
			
		const T & front( ) const;
				
		T & back( );
	
		const T & back( ) const;
				
		void push_front( const T & value );
					
		void push_back( const T & value );
		
		void pop_front( );
				
		void pop_back( );
				
		void assign(int count, const T& value );
			
		// [IV-a] Modifiers with iterators

		template < class InItr >

		void assign( InItr first, InItr last );

		void assign( std::initializer_list<T> ilist );

		iterator insert( const_iterator itr, const T & value );

		iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		
		template <typename InItr>	
		iterator insert(iterator pos, InItr first, InItr last);
	
		iterator erase( const_iterator itr );

		iterator erase( iterator first, iterator last );

		const_iterator find( const T & value ) const;
		
};
	template <typename T>
	bool operator==(const list<T>& lhs,const list<T>& rhs);
	template <typename T>
	bool operator!=(const list<T>& lhs,const list<T>& rhs);

}

#include "list.inl"
#endif
