#include <dynobj/object_host.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace dynobj {
using ::testing::_;

class LogReceiverMock : public ILogReceiver {
 public:
    MOCK_METHOD(void, BracketOperator, (LogLevel level, const char* str));
    void operator()(LogLevel level, const char* str) override {
        return BracketOperator(level, str);
    }
};

TEST(ObjectHostTests, start_finish) {
    LogReceiverMock log_rcv;
    EXPECT_CALL(log_rcv, BracketOperator(STATUS, _)).Times(2);

    auto obj_host = IDynamicObjectHost::createInstance(&log_rcv);
    obj_host.reset();
}

}  // namespace dynobj