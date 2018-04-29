#include <iostream>
#include <cstdlib>

#include <boost/asio/io_service.hpp>
#include <boost/asio/local/stream_protocol.hpp>
#include <boost/system/error_code.hpp>

namespace basio = boost::asio;

namespace {

bool runClient_();
}  // unnamed namespace

/// @brief Unix domain socket を利用した通信クライアントのエントリポイント
int main()
{
  std::cout << "start unix domain socket client.\n";

  if (runClient_() == false) {
    std::cerr << "error occured.\n";
    return EXIT_FAILURE;
  }

  std::cout << "end unix domain socket client.\n";
  return EXIT_SUCCESS;
}

namespace {

/// @brief TCPクライアントの起動
bool runClient_()
{
  basio::io_service service;
  basio::local::stream_protocol::endpoint ep("/tmp/udsocket");
  basio::local::stream_protocol::socket s(service);
  boost::system::error_code ec;
  s.connect(ep, ec);
  if (ec) {
    std::cerr << "error occured: " << ec;
    return false;
  }

  return true;
}
}  // unnamed namespace
