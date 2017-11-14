// 
// #ifndef STACK_T
// # define STACK_T
//
// # include <deque>
// # include <stack>
//
//
// //A CHANGER
// template <class T> class Stack : public std::stack<T> {
// public:
// 	typedef typename std::deque<T>::iterator iterator;
// 	Stack( void );
// 	Stack( Stack const & obj );
// 	~Stack( void );
// 	Stack & operator=( Stack const & rhs );
//
// 	Stack<T>::iterator begin( void );
// 	Stack<T>::iterator end( void );
// protected:
//
// private:
//
// };
//
// template <class T> Stack<T>::Stack( void ) {}
// template <class T> Stack<T>::Stack( Stack<T> const & obj ) { *this = obj; }
// template <class T> Stack<T>::~Stack( void ) {}
// template <class T> Stack<T> & Stack<T>::operator=( Stack<T> const & rhs ) {
// 	this->std::stack<T>::operator=(rhs);
// 	return *this;
// }
// template <class T> typename Stack<T>::iterator Stack<T>::begin( void ) {
// 	return this->c.begin();
// }
// template <class T> typename Stack<T>::iterator Stack<T>::end( void ) {
// 	return this->c.end();
// }
//
// #endif
