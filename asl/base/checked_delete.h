#ifndef BOOST_CHECKED_DELETE_HPP_INCLUDED
#define BOOST_CHECKED_DELETE_HPP_INCLUDED

#if _MSC_VER >= 1020
#pragma once
#endif

//
//  boost/checked_delete.hpp
//
//  Copyright (c) 1999, 2000, 2001, 2002 boost.org
//
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.
//

namespace asl
{


/*! \addtogroup aslbase */
/* @{ */
    
// verify that types are complete for increased safety

template< typename T > inline void checked_delete(T * x)
{
    typedef char type_must_be_complete[sizeof(T)];

    //AC_TRACE << "checked_delete(x) called for ptr " << x << endl;
    delete x;
}

template< typename T > inline void checked_array_delete(T * x)
{
    typedef char type_must_be_complete[sizeof(T)];
    delete [] x;
}

template<class T> struct checked_deleter
{
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x)
    {
        checked_delete(x);
    }
};

// checked_deleter<void> is needed by shared_ptr<void>::reset(0)

template<> struct checked_deleter<void>
{
    typedef void result_type;
    typedef void * argument_type;

    void operator()(void * x)
    {
        ::operator delete(x); // avoid g++ warning
    }
};

template<class T> struct checked_array_deleter
{
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x)
    {
        checked_array_delete(x);
    }
};

/* @} */

} // namespace boost

#endif  // #ifndef BOOST_CHECKED_DELETE_HPP_INCLUDED
