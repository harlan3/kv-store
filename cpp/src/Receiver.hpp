//
// Receiver.cpp
// ~~~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef RECEIVER_HPP_
#define RECEIVER_HPP_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class Receiver {
public:
    Receiver(boost::asio::io_service& io_service,
            const boost::asio::ip::address& listen_address,
            const boost::asio::ip::address& multicast_address,
            short multicast_port) :
            socket_(io_service) {

        // Create the socket so that multiple may be bound to the same address.
        boost::asio::ip::udp::endpoint listen_endpoint(listen_address,
                multicast_port);
        socket_.open(listen_endpoint.protocol());
        socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
        socket_.bind(listen_endpoint);

        // Join the multicast group.
        socket_.set_option(
                boost::asio::ip::multicast::join_group(multicast_address));

        socket_.async_receive_from(boost::asio::buffer(data_, max_length),
                sender_endpoint_,
                boost::bind(&Receiver::handleReceiveFrom, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
    }

    void setCallback(boost::function<void(char *, int)> callback) {
        receiveCallback = callback;
    }

    void handleReceiveFrom(const boost::system::error_code& error,
            size_t bytes_recvd) {
        if (!error) {
            receiveCallback(&data_[0], bytes_recvd);

            socket_.async_receive_from(boost::asio::buffer(data_, max_length),
                    sender_endpoint_,
                    boost::bind(&Receiver::handleReceiveFrom, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
        }
    }

private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    boost::function<void(char *, int)> receiveCallback;
    enum {
        max_length = 65535
    };
    char data_[max_length];
};

#endif /* RECEIVER_HPP_ */
