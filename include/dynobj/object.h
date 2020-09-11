//
// Deep Water project
//

/*!
    \file
    \brief  Base Interface of all dynamic loaded objects.
    \author Aleksei Khozin <ahozin@hotmail.com>
    \date   September 2020

    The file contains definition of interface that is a base for dynamic loaded object.
*/

#pragma once

#include <boost/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

namespace deep_water {
namespace objects {

/*!
    \brief Dynamic loaded object base interface.

    Every dynamic loaded object is inherited from this interface.
*/
class IObject : boost::intrusive_ref_counter<IObject, boost::thread_safe_counter> {
 public:
    //! Mandatory base virtual destructor.
    virtual ~IObject() = default;
};

}  // namespace objects
}  // namespace deep_water