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
#include <dynobj/callback.h>
#include <dynobj/log_level.h>

namespace dynobj {

class IDynamicObjectHost;
DYNOBJ_DECLARE_PTR(IDynamicObjectHost);

/*!
    \brief Interface of dynamic object host.

    Dynamic object host is container for dynamic object contexts.
*/
class IDynamicObjectHost : public IRefCounter {
 public:
    //! Callback type to receive logging messages.
    using ILogReceiver = ICallback<void(LogLevel, const char*)>;

    /*!
        \brief Safely creates an instance of the host object.

        \return intrusive smart pointer to binary-safe pointer
    */
    static IDynamicObjectHostPtr createInstance(ILogReceiver* log_rcv) {
        return createInstancePrivate(log_rcv);
    }

    /*!
        \brief Loads a context from config string and then runs it.

        Contexts are stored in LIFO ordered container.
        The first loaded context is most major and destroyed in the last place.

        \param config string with json-style configuration of a context
        \par
            Format of context configuration:
            \code{.json}
            {
                "name" : "<context name>",
                "objects" : [
                    <array of objects>
                ]
            }
            \endcode
            Configuration of every object in the array should have the following format:
            \code{.json}
            {
                "module" : "<library name>",
                "name"   : "<object class name>"
                "id"     : "<unique identifier>"
                "connections" : [
                    <array of object connections>
                ]
            }
            \endcode

        \param log_rcv pointer to logging message receiver

        \return \c true if the context was loaded successfully.
    */
    virtual bool loadContext(const char* config) = 0;

    /*!
        \brief Drops last loaded context.

        \see loadContext.

        \return `true` if a context was dropped.
        \par
            For example you can release all contexts with following code:
            \code{.cpp}
            while(host_object->dropContext());
            \endcode
    */
    virtual bool dropContext() = 0;

 private:
    static IDynamicObjectHost* createInstancePrivate(ILogReceiver* log_rcv);
};

}  // namespace dynobj