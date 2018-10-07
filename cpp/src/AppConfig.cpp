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

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "AppConfig.hpp"

void AppConfig::loadXml(const std::string &filename) {
    boost::property_tree::ptree tree;
    boost::property_tree::read_xml(filename, tree);
    std::string endianString;

    listenAddress = tree.get<std::string>("config.listenAddress");
    multicastAddress = tree.get<std::string>("config.multicastAddress");
    multicastPort = tree.get<int>("config.multicastPort");
    recvLoopSleepTime = tree.get<int>("config.recvLoopSleepTime");
    sendLoopSleepTime = tree.get<int>("config.sendLoopSleepTime");
    publisherID = tree.get<int>("config.publisherID");
    endianString = tree.get<std::string>("config.endianness");

    if (endianString == "BIG_ENDIAN")
        endianness = (kvstore_ns::ARCH_Info) 0;
    else if (endianString == "LITTLE_ENDIAN")
        endianness = (kvstore_ns::ARCH_Info) 1;

    processCallbacks = tree.get<bool>("config.processCallbacks");
}

std::string AppConfig::getListenAddress() {

    return listenAddress;
}

std::string AppConfig::getMulticastAddress() {

    return multicastAddress;
}

int AppConfig::getMulticastPort() {

    return multicastPort;
}

int AppConfig::getRecvLoopSleepTime() {

    return recvLoopSleepTime;
}

int AppConfig::getSendLoopSleepTime() {

    return sendLoopSleepTime;
}

int AppConfig::getPublisherID() {

    return publisherID;
}

kvstore_ns::ARCH_Info AppConfig::getEndianness() {

    return endianness;
}

bool AppConfig::getProcessCallbacks() {

    return processCallbacks;
}
