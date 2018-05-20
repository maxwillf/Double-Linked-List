#ifndef lista_
#define lista_
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

					Node(const T & d = T () , Node *p = nullptr, Node *n = nullptr)
						: data (d),prev (p), next (n) {}
				};
			public :
				class const_iterator{
					public :
						const_iterator( );
						const T & operator * ( ) const;
						const_iterator & operator ++ ( );
						// ++it;
						const_iterator operator ++ ( int ); // it++;
						const_iterator & operator -- ( );
						// --it;
						const_iterator operator -- ( int ); // it--;
						bool operator == ( const const_iterator & rhs ) const;
						bool operator != ( const const_iterator & rhs ) const;
					protected :
						Node *current;
				//		const_iterator( Node * p ) : current( p ){}
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
				//		iterator( Node *p ) : const_iterator( p ){};
						friend class list<T>;

				};
				// [I] SPECIAL MEMBERS
				list(void);
				~list( );
				list( const list & );
				list & operator = ( const list & );
				// [II] ITERATORS
				iterator begin( );
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

			private :
				int m_size;
				Node *m_head;
				Node *m_tail;

		};
}
#include "list.inl"
#endif
