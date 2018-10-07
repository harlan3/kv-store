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

#ifndef KV_STORE_HPP_
#define KV_STORE_HPP_

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>
#include <boost/signals2.hpp>
#include <boost/ptr_container/ptr_map.hpp>

#include "AppConfig.hpp"
#include "SharedQueue.hpp"
#include "KVSObject.hpp"

namespace kvstore {

typedef boost::function<void()> Callback;
typedef boost::signals2::signal<void()> Signal;
typedef boost::shared_ptr<Signal> SignalPtr;
}

class KVStore {

public:

    // Create object setting publisherID
    KVStore();

    // Start that must be called prior to any other methods
    void start();

    // Shutdown request
    void shutdownReq();

    // Returns true when thread is complete
    bool threadsAreComplete();

    // *********** Start of the single value setter/getter methods ***********

    void setInt32Value(std::string key, int32_t value);
    int32_t getInt32Value(std::string key);

    void setInt64Value(std::string key, int64_t value);
    int64_t getInt64Value(std::string key);

    void setFloatValue(std::string key, float value);
    float getFloatValue(std::string key);

    void setDoubleValue(std::string key, double value);
    double getDoubleValue(std::string key);

    void setBoolValue(std::string key, bool value);
    bool getBoolValue(std::string key);

    void setStringValue(std::string key, std::string value);
    std::string getStringValue(std::string key);

    void setByteBufferValue(std::string key, int8_t* byteBuffer,
            int byteBufferLength);
    int32_t getByteBufferValue(std::string key, int8_t* byteBuffer);

    void postEvent(std::string key);

    // ***********  Start of the array setter/getter methods  ***********

    void setInt32Array(std::string key, int32_t array[], int arrayLength);
    int32_t getInt32Array(std::string key, int32_t array[]);

    void setInt64Array(std::string key, int64_t array[], int arrayLength);
    int32_t getInt64Array(std::string key, int64_t array[]);

    void setFloatArray(std::string key, float array[], int arrayLength);
    int32_t getFloatArray(std::string key, float array[]);

    void setDoubleArray(std::string key, double array[], int arrayLength);
    int32_t getDoubleArray(std::string key, double array[]);

    void setBoolArray(std::string key, bool array[], int arrayLength);
    int32_t getBoolArray(std::string key, bool array[]);

    // **************  Start of the callback support methods  ***************

    void registerHandler(std::string key, kvstore::Callback callbackHandle);
    void disconnectHandlers(std::string key);

private:

    void runPublishThread();
    void buildPublishBuffer();

    void runReceiveThread();
    void processRcvCallback(char *data, int numBytes);

    AppConfig appConfig;

    boost::thread* publishThread;
    boost::thread* receiveThread;

    kvstore_ns::Transaction pubTransaction;
    kvstore_ns::Transaction rcvTransaction;

    boost::asio::io_service io_service_p;
    boost::asio::io_service io_service_r;

    bool shutdownRequested;
    bool publishThreadComplete;
    bool receiveThreadComplete;
    int publisherID;

    std::string publishBuffer;
    bool sendPublishBuffer;

    kvstore_ns::ARCH_Info systemByteOrder;
    SharedQueue<KVSObject> pubQueue;
    std::map<std::string, KVSObject> dataStore;
    boost::ptr_map<std::string, kvstore::SignalPtr> signalLookup;
    boost::mutex mutex;
};

#endif /* KV_STORE_HPP_ */
