//
// Dynamic Loaded Object Toolkit
//

/*!
    \file
    \brief  Interface declaration of host object for dynamic loaded objects.
    \author Aleksei Khozin <ahozin@hotmail.com>
    \date   September 2020

    The file contains declaration of host object interface.
*/

#pragma once

#include <dynobj/ref_counter.h>

#include <boost/intrusive_ptr.hpp>

namespace dynobj {

/*!
    \brief Interface of dynamic object host.

    Dynamic object host is container for dynamic object contexts.
*/
class IDynamicObjectHost : public IRefCounter {
 public:
    static boost::intrusive_ptr<IDynamicObjectHost> createInstance() {
        return createInstancePrivate();
    }

 private:
    static IDynamicObjectHost* createInstancePrivate();
};

}  // namespace dynobj