//
// Dynamic Loaded Object Toolkit
//

/*!
    \file
    \brief  Declaration of callback interface.
    \author Aleksei Khozin <ahozin@hotmail.com>
    \date   September 2020

    The file contains declaration of callback interface.
*/

#pragma once

namespace dynobj {

template <typename F>
class ICallback;

template <typename R, typename... Args>
class ICallback<R(Args...)> {
 public:
    virtual R operator()(Args...) = 0;
};

}  // namespace dynobj