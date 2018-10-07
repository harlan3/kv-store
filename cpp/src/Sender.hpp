//
// Sender.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SENDER_HPP_
#define SENDER_HPP_

#include <boost/asio.hpp>
#include <boost/bind.hpp>

class Sender {
public:
    Sender(boost::asio::io_service& io_service,
            const boost::asio::ip::address& multicast_address,
            short multicast_port) :
            endpoint_(multicast_address, multicast_port), socket_(io_service,
                    endpoint_.protocol()), timer_(io_service), message_count_(0) {
    }

    void sendTo(std::string message) {
        socket_.async_send_to(boost::asio::buffer(message), endpoint_,
                boost::bind(&Sender::handler, this,
                        boost::asio::placeholders::error));
    }

    void handler(const boost::system::error_code& error) {
    }

private:
    boost::asio::ip::udp::endpoint endpoint_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::deadline_timer timer_;
    int message_count_;

};

#endif /* SENDER_HPP_ */
