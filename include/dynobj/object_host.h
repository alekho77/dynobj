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

namespace dynobj {

/*!
    \brief Interface of dynamic object host.

    Dynamic object host is container for dynamic object contexts.
*/
class IDynamicObjectHost : public IRefCounter {
 public:
};

}  // namespace dynobj