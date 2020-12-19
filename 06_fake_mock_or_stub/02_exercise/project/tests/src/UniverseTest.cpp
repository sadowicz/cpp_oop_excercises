#include "Universe.h"
#include "SpaceMock.h"
#include "ObserverMock.h"
#include "TimeMock.h"
#include "TestIncludes.h"

class Socket {
public:

    virtual ~Socket() = default;

    virtual std::string receive() const = 0;
    virtual void send(const std::string& message) = 0;
};

class Server {
public:

    explicit Server(Socket &socket) : socket(socket) {}

    void run() {

        auto request = socket.receive();

        auto response = "Hello " + request;

        socket.send(response);
    }

private:
    Socket& socket;
};

class SocketMock : public Socket {
public:

    MOCK_CONST_METHOD0(receive, std::string());
    MOCK_METHOD1(send, void(const std::string& message));
};

TEST(Socket, SendAndReceive) {

    StrictMock<SocketMock> socket{};
    Server server{socket};

    EXPECT_CALL(socket, receive()).WillOnce(Return("Tom"));
    EXPECT_CALL(socket, send("Hello Tom"));

    server.run();
}

TEST(Universe, Constructor)
{
    TimeMock time{};
    SpaceMock space{};
    ObserverMock observer{};

    Universe universe{time, space, observer};
}

TEST(Universe, Create_RemembersCorrectNumberOfDimensions)
{
    NiceMock<TimeMock> time{};
    SpaceMock space{};
    ObserverMock observer{};

    Universe universe{time, space, observer};

    EXPECT_CALL(space, create(11));
    EXPECT_CALL(space, dimensions).WillOnce(Return(11));
    EXPECT_CALL(observer, remember("How many dimensions there are?", std::to_string(11)));

    universe.create();

    EXPECT_CALL(observer, answer("How many dimensions there are?")).WillOnce(Return("11"));

    observer.answer("How many dimensions there are?");
}

TEST(Universe, Simulate_NoEarthBefore9300000000)
{
    NiceMock<TimeMock> time{};
    NiceMock<SpaceMock> space{};
    NiceMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(9299999999));

    universe.simulate(9299999999);

    EXPECT_CALL(observer, answer("Is there planet Earth?")).WillOnce(Return("I do not know..."));

    observer.answer("Is there planet Earth?");
}

TEST(Universe, Simulate_EarthAppearsAt9300000000)
{
    NiceMock<TimeMock> time{};
    NiceMock<SpaceMock> space{};
    NiceMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(9300000000));

    universe.simulate(9300000000);

    EXPECT_CALL(observer, answer("Is there planet Earth?")).WillOnce(Return("Yes!"));

    observer.answer("Is there planet Earth?");
}

TEST(Universe, Simulate_NoLifeBefore9900000000)
{
    NiceMock<TimeMock> time{};
    NiceMock<SpaceMock> space{};
    NiceMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(9899999999));

    universe.simulate(9899999999);

    EXPECT_CALL(observer, answer("Does life exist?")).WillOnce(Return("I do not know..."));

    observer.answer("Does life exist?");
}

TEST(Universe, Simulate_LifeAppearsAt9900000000)
{
    NiceMock<TimeMock> time{};
    NiceMock<SpaceMock> space{};
    NiceMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(9900000000));

    universe.simulate(9900000000);

    EXPECT_CALL(observer, answer("Does life exist?")).WillOnce(Return("Yes!"));

    observer.answer("Does life exist?");
}

TEST(Universe, Simulate_NoPeopleBefore13800000000)
{
    NiceMock<TimeMock> time{};
    NiceMock<SpaceMock> space{};
    NiceMock<ObserverMock> observer{};

    Universe universe{time, space, observer};

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(13799999999));

    universe.simulate(13799999999);

    EXPECT_CALL(observer, answer("Have People evolved?")).WillOnce(Return("I do not know..."));

    observer.answer("Have People evolved?");
}