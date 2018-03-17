#include <iostream>
#include <cstdlib>
#include <string>

#include <boost/asio/io_service.hpp>
#include <boost/asio/local/stream_protocol.hpp>
#include <boost/system/error_code.hpp>

namespace basio = boost::asio;

namespace {

bool runServer_();
}  // unnamed namespace

/// @brief Unix domain socket を利用した通信サーバのエントリポイント
int main()
{
  std::cout << "start unix domain socket server.\n";

  if (runServer_() == false) {
    std::cerr << "error occured in process.\n";
    return EXIT_FAILURE;
  }

  std::cout << "end unix domain socket server.\n";
  return EXIT_SUCCESS;
}

namespace {

/// @brief サーバーの起動と一定間隔でのデータ転送
bool runServer_()
{
  basio::io_service service;
  basio::local::stream_protocol::endpoint ep("/tmp/udsocket");
  basio::local::stream_protocol::acceptor acceptor(service, ep);
  basio::local::stream_protocol::socket s(service);
  boost::system::error_code ec;
  acceptor.accept(s, ec);
  if (ec) {
    std::cerr << "error occured: " << ec;
    return false;
  }

  return true;
}
}  // unnamed namespace
