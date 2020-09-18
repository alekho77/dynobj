//
// Dynamic Loaded Object Toolkit
//

/*!
    \file
    \brief  Declaration of logging level constants.
    \author Aleksei Khozin <ahozin@hotmail.com>
    \date   September 2020

    The file contains declaration of logging level constants.
*/

#pragma once

#include <dynobj/callback.h>

namespace dynobj {

//! Logging levels type.
enum LogLevel {
    Error = -3,    //< critical problem that leads to stop any further processing
    Warning = -2,  //< significant problem that can lead to wrong behavior
    Notice = -1,   //< minor problem that could lead to some unnecessary side effects
    Status = 0,    //< brief information about normal work progress
    Verbose = 1,   //< verbose information about normal work progress
    Debug = 2,     //< additional debug information about progress
    Trace = 3      //< extended debug information
};

constexpr auto ERROR = LogLevel::Error;
constexpr auto WARNING = LogLevel::Warning;
constexpr auto NOTICE = LogLevel::Notice;
constexpr auto STATUS = LogLevel::Status;
constexpr auto VERBOSE = LogLevel::Verbose;
constexpr auto DEBUG = LogLevel::Debug;
constexpr auto TRACE = LogLevel::Trace;

//! Callback type to receive logging messages.
using ILogReceiver = ICallback<void(LogLevel, const char*)>;

}  // namespace dynobj