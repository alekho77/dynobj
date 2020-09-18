//
// Dynamic Loaded Object Toolkit
//

#include <dynobj/object_host.h>

#include <sstream>

namespace dynobj {

namespace {

class LogStream {
 public:
    explicit LogStream(LogLevel level, ILogReceiver* rcv) : level_(level), rcv_(rcv) {}
    ~LogStream() {
        if (rcv_) {  // if no receiver, log is dropped.
            (*rcv_)(level_, str_.str().c_str());
        }
    }

    template <typename T>
    friend LogStream& operator<<(LogStream& log, T&& value) {
        log.str_ << std::forward<T>(value);
        return log;
    }

 private:
    const LogLevel level_;
    ILogReceiver* const rcv_;
    std::stringstream str_;
};

class ObjectHostImpl : public IDynamicObjectHost {
 public:
    explicit ObjectHostImpl(ILogReceiver* log_rcv);
    ~ObjectHostImpl();

 private:  // IDynamicObjectHost
    bool loadContext(const char* config) final;
    bool dropContext() final;

 private:
    LogStream writeLog(LogLevel level) const;

 private:
    ILogReceiver* const log_rcv_;
};

ObjectHostImpl::ObjectHostImpl(ILogReceiver* log_rcv) : log_rcv_(log_rcv) {
    writeLog(STATUS) << "Dynamic Object Host has started";
}

ObjectHostImpl::~ObjectHostImpl() {
    writeLog(STATUS) << "Dynamic Object Host has finished";
}

bool ObjectHostImpl::loadContext(const char* config) {
    writeLog(ERROR) << "Not implemented";
    return false;
}

bool ObjectHostImpl::dropContext() {
    writeLog(ERROR) << "Not implemented";
    return false;
}

LogStream ObjectHostImpl::writeLog(LogLevel level) const {
    return LogStream(level, log_rcv_);
}

}  // namespace

IDynamicObjectHost* IDynamicObjectHost::createInstancePrivate(ILogReceiver* log_rcv) {
    return new detail::RefCounter<ObjectHostImpl>(log_rcv);
}

}  // namespace dynobj