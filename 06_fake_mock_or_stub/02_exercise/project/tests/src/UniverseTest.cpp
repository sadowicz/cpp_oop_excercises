#include "Universe.h"
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

TEST(Universe, Create)
{
    // TODO: Test Universe class...
}
