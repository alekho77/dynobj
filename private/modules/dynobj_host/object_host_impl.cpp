//
// Dynamic Loaded Object Toolkit
//

#include <dynobj/object_host.h>

namespace dynobj {

namespace {

class ObjectHostImpl : public IDynamicObjectHost {
 public:
 private:
};

}  // namespace

IDynamicObjectHost* IDynamicObjectHost::createInstancePrivate() {
    return new detail::RefCounter<ObjectHostImpl>();
}

}  // namespace dynobj