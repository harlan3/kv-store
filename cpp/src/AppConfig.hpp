/*
 *  KVStore - A distributed key value store supporting a common set of data
 *  types and arrays over a multicast network.
 *
 *  Copyright (C) 2017 Harlan Murphy
 *  harlan3@hotmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License Version 3 dated 29 June 2007, as published by the
 *  Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library.  If not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <string>

#include "KVStore.pb.h"

class AppConfig {

public:

    void loadXml(const std::string &filename);

    std::string getListenAddress();
    std::string getMulticastAddress();
    int getMulticastPort();
    int getRecvLoopSleepTime();
    int getSendLoopSleepTime();
    int getPublisherID();
    kvstore_ns::ARCH_Info getEndianness();
    bool getProcessCallbacks();

private:
    std::string listenAddress;
    std::string multicastAddress;
    int multicastPort;
    int recvLoopSleepTime;
    int sendLoopSleepTime;
    int publisherID;
    kvstore_ns::ARCH_Info endianness;
    bool processCallbacks;
};
