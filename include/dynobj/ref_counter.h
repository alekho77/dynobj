//
// Dynamic Loaded Object Toolkit
//

/*!
    \file
    \brief  Declarations to support reference counting of dynamic loaded objects.
    \author Aleksei Khozin <ahozin@hotmail.com>
    \date   September 2020

    The file contains definitions to provide reference counting of dynamic loaded objects.
*/

#pragma once

#include <boost/intrusive_ptr.hpp>

#include <utility>
#include <atomic>

//! Macro to define concrete pointer with given class.
#define DYNOBJ_DECLARE_PTR(Class) using Class##Ptr = boost::intrusive_ptr<Class>

namespace dynobj {

/*!
    \brief Interface to reference counting.

    This interface is base for each dynamic loaded object.
 */
class IRefCounter {
 public:
    //! Increase references count.
    virtual void addRef() const = 0;
    /*!
        \brief Decrease references count.

        Object is destroyed if counter reaches 0.
     */
    virtual void release() const = 0;

 protected:
    //! Protected virtual destructor.
    virtual ~IRefCounter() = default;
};

/*!
    \brief IRefCounter - intrusive_ptr connection.
 */
inline void intrusive_ptr_add_ref(const IRefCounter* itf) {
    itf->addRef();
}

/*!
    \brief IRefCounter - intrusive_ptr connection.
 */
inline void intrusive_ptr_release(const IRefCounter* itf) {
    itf->release();
}

namespace detail {
/*!
    \brief A reference counter class implementation.

    \implements IRefCounter

    \tparam T   User-defined class or interface that will be wrapped to add implementation of reference counting.
*/
template <typename T>
class RefCounter : public T {
 public:
    /*!
        \brief Constructor with a number of parameters.

        \tparam Args   Parameters type
        \param  args   Arguments list
     */
    template <typename... Args>
    explicit RefCounter(Args&&... args) : T(std::forward<Args>(args)...) {}

    /*! @copydoc IRefCounter::addRef */
    void addRef() const override {
        ref_counter_.fetch_add(1, std::memory_order_relaxed);
    }

    /*! @copydoc IRefCounter::release */
    void release() const override {
        if (ref_counter_.fetch_sub(1, std::memory_order_release) == 1) {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete this;
        }
    }

    RefCounter& operator=(const RefCounter& rhs) = delete;

 protected:
    ~RefCounter() = default;
    RefCounter(const RefCounter& from) : T(from) {}
    explicit RefCounter(RefCounter&& from) : T(std::move(from)) {}

 private:
    mutable std::atomic_int ref_counter_{0};
};

}  // namespace detail
}  // namespace dynobj