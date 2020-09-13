//
// Dynamic Loaded Object Toolkit
//

#include <dynobj/object_host.h>

#include <sstream>

namespace dynobj {

namespace {

class ObjectHostImpl : public IDynamicObjectHost {
    class LogStream {
     public:
        explicit LogStream(LogLevel level, ILogReceiver* log_rcv);
    };

 public:
 private:  // IDynamicObjectHost
    bool loadContext(const char* config, ILogReceiver* log_rcv) final;
    bool dropContext() final;

 private:
};

bool ObjectHostImpl::loadContext(const char* config, ILogReceiver* log_rcv) {
    return false;
}

bool ObjectHostImpl::dropContext() {
    return false;
}

}  // namespace

IDynamicObjectHost* IDynamicObjectHost::createInstancePrivate() {
    return new detail::RefCounter<ObjectHostImpl>();
}

}  // namespace dynobj