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

#include "KVStore.hpp"

#include <boost/bind.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

#include "ByteSwapper.hpp"
#include "Sender.hpp"
#include "Receiver.hpp"

KVStore::KVStore() {

    appConfig.loadXml("config.xml");

    shutdownRequested = false;
    publishThreadComplete = false;
    receiveThreadComplete = false;

    systemByteOrder = appConfig.getEndianness();
    publisherID = appConfig.getPublisherID();
}

void KVStore::start() {

    publishThread = new boost::thread(
            boost::bind(&KVStore::runPublishThread, this));
    receiveThread = new boost::thread(
            boost::bind(&KVStore::runReceiveThread, this));
}

void KVStore::shutdownReq() {

    shutdownRequested = true;

    io_service_p.stop();
    io_service_r.stop();
}

bool KVStore::threadsAreComplete() {

    return publishThreadComplete && receiveThreadComplete;
}

void KVStore::setInt32Value(std::string key, int32_t value) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_INT32;
    kvsObject.numberElements = 1;
    kvsObject.byteBuffer.resize(sizeof(value));
    memcpy(&kvsObject.byteBuffer[0], &value, sizeof(value));

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getInt32Value(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    int32_t value = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if ((kvsObject.typeInfo != kvstore_ns::TYPE_INT32)
                    || (kvsObject.numberElements != 1)) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            memcpy(&value, &kvsObject.byteBuffer[0], sizeof(value));
        }
    }

    return value;
}

void KVStore::setInt64Value(std::string key, int64_t value) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_INT64;
    kvsObject.numberElements = 1;
    kvsObject.byteBuffer.resize(sizeof(value));
    memcpy(&kvsObject.byteBuffer[0], &value, sizeof(value));

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int64_t KVStore::getInt64Value(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    int64_t value = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if ((kvsObject.typeInfo != kvstore_ns::TYPE_INT64)
                    || (kvsObject.numberElements != 1)) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            memcpy(&value, &kvsObject.byteBuffer[0], sizeof(value));
        }
    }

    return value;
}

void KVStore::setFloatValue(std::string key, float value) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_FLOAT;
    kvsObject.numberElements = 1;
    kvsObject.byteBuffer.resize(sizeof(value));
    memcpy(&kvsObject.byteBuffer[0], &value, sizeof(value));

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

float KVStore::getFloatValue(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    float value = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if ((kvsObject.typeInfo != kvstore_ns::TYPE_FLOAT)
                    || (kvsObject.numberElements != 1)) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            memcpy(&value, &kvsObject.byteBuffer[0], sizeof(value));
        }
    }

    return value;
}

void KVStore::setDoubleValue(std::string key, double value) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_DOUBLE;
    kvsObject.numberElements = 1;
    kvsObject.byteBuffer.resize(sizeof(value));
    memcpy(&kvsObject.byteBuffer[0], &value, sizeof(value));

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

double KVStore::getDoubleValue(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    double value = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if ((kvsObject.typeInfo != kvstore_ns::TYPE_DOUBLE)
                    || (kvsObject.numberElements != 1)) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            memcpy(&value, &kvsObject.byteBuffer[0], sizeof(value));
        }
    }

    return value;
}

void KVStore::setBoolValue(std::string key, bool value) {

    boost::mutex::scoped_lock lock(mutex);

    uint8_t byteValue = (uint8_t) ((value == false) ? 0 : 1);
    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_BOOL;
    kvsObject.numberElements = 1;
    kvsObject.byteBuffer.resize(sizeof(byteValue));
    memcpy(&kvsObject.byteBuffer[0], &byteValue, sizeof(byteValue));

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

bool KVStore::getBoolValue(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    bool value = false;
    uint8_t byteValue = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if ((kvsObject.typeInfo != kvstore_ns::TYPE_BOOL)
                    || (kvsObject.numberElements != 1)) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            memcpy(&byteValue, &kvsObject.byteBuffer[0], sizeof(byteValue));
            value = (byteValue == 0) ? false : true;
        }
    }

    return value;
}

void KVStore::setStringValue(std::string key, std::string value) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (value.length() < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_STRING;
    kvsObject.numberElements = value.length() + 1;
    kvsObject.byteBuffer.resize(value.length() + 1);
    memcpy(&kvsObject.byteBuffer[0], value.c_str(), value.length());

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

std::string KVStore::getStringValue(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    std::string value = "";
    char* c_str_value;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_STRING) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return value;
            }

            c_str_value = (char *) &kvsObject.byteBuffer[0];
            c_str_value[(kvsObject.numberElements - 1)] = '\0';
            value = std::string(c_str_value);
        }
    }

    return value;
}

void KVStore::setByteBufferValue(std::string key, int8_t* byteBuffer,
        int byteBufferLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (byteBufferLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_BYTES;
    kvsObject.numberElements = byteBufferLength;
    kvsObject.byteBuffer.resize(byteBufferLength);
    memcpy(&kvsObject.byteBuffer[0], byteBuffer, byteBufferLength);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getByteBufferValue(std::string key, int8_t* byteBuffer) {

    boost::mutex::scoped_lock lock(mutex);

    int byteBufferLength = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_BYTES) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return byteBufferLength;
            }

            byteBufferLength = kvsObject.numberElements;
            memcpy(byteBuffer, &kvsObject.byteBuffer[0],
                    kvsObject.numberElements);
        }
    }

    return byteBufferLength;
}

void KVStore::postEvent(std::string key) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_EVENT;
    kvsObject.numberElements = 0;

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

void KVStore::setInt32Array(std::string key, int32_t array[], int arrayLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (arrayLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_INT32;
    kvsObject.numberElements = arrayLength;
    kvsObject.byteBuffer.resize(arrayLength * 4);
    memcpy(&kvsObject.byteBuffer[0], &array[0], arrayLength * 4);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getInt32Array(std::string key, int32_t array[]) {

    boost::mutex::scoped_lock lock(mutex);

    int numberElements = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_INT32) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return numberElements;
            }

            numberElements = kvsObject.numberElements;
            memcpy(&array[0], &kvsObject.byteBuffer[0], (numberElements * 4));
        }
    }

    return numberElements;
}

void KVStore::setInt64Array(std::string key, int64_t array[], int arrayLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (arrayLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_INT64;
    kvsObject.numberElements = arrayLength;
    kvsObject.byteBuffer.resize(arrayLength * 8);
    memcpy(&kvsObject.byteBuffer[0], &array[0], arrayLength * 8);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getInt64Array(std::string key, int64_t array[]) {

    boost::mutex::scoped_lock lock(mutex);

    int numberElements = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_INT64) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return numberElements;
            }

            numberElements = kvsObject.numberElements;
            memcpy(&array[0], &kvsObject.byteBuffer[0], (numberElements * 8));
        }
    }

    return numberElements;
}

void KVStore::setFloatArray(std::string key, float array[], int arrayLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (arrayLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_FLOAT;
    kvsObject.numberElements = arrayLength;
    kvsObject.byteBuffer.resize(arrayLength * 4);
    memcpy(&kvsObject.byteBuffer[0], &array[0], arrayLength * 4);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getFloatArray(std::string key, float array[]) {

    boost::mutex::scoped_lock lock(mutex);

    int numberElements = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_FLOAT) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return numberElements;
            }

            numberElements = kvsObject.numberElements;
            memcpy(&array[0], &kvsObject.byteBuffer[0], (numberElements * 4));
        }
    }

    return numberElements;
}

void KVStore::setDoubleArray(std::string key, double array[], int arrayLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (arrayLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_DOUBLE;
    kvsObject.numberElements = arrayLength;
    kvsObject.byteBuffer.resize(arrayLength * 8);
    memcpy(&kvsObject.byteBuffer[0], &array[0], arrayLength * 8);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getDoubleArray(std::string key, double array[]) {

    boost::mutex::scoped_lock lock(mutex);

    int numberElements = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_DOUBLE) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return numberElements;
            }

            numberElements = kvsObject.numberElements;
            memcpy(&array[0], &kvsObject.byteBuffer[0], (numberElements * 8));
        }
    }

    return numberElements;
}

void KVStore::setBoolArray(std::string key, bool array[], int arrayLength) {

    boost::mutex::scoped_lock lock(mutex);

    KVSObject kvsObject;

    if (arrayLength < 1)
        return;

    kvsObject.key = key;
    kvsObject.typeInfo = kvstore_ns::TYPE_BOOL;
    kvsObject.numberElements = arrayLength;
    kvsObject.byteBuffer.resize(arrayLength * 1);
    memcpy(&kvsObject.byteBuffer[0], &array[0], arrayLength * 1);

    dataStore[key] = kvsObject;

    pubQueue.push(kvsObject);

    if (appConfig.getProcessCallbacks()) {

        if (signalLookup.count(key) > 0) {

            signalLookup[key]->operator()();
        }
    }
}

int32_t KVStore::getBoolArray(std::string key, bool array[]) {

    boost::mutex::scoped_lock lock(mutex);

    int numberElements = 0;

    if (!key.empty()) {

        if (dataStore.count(key) > 0) {

            KVSObject kvsObject = dataStore[key];

            if (kvsObject.typeInfo != kvstore_ns::TYPE_BOOL) {
                std::cerr << "KeyValue store type mismatch for key: " << key
                        << std::endl;
                return numberElements;
            }

            numberElements = kvsObject.numberElements;
            memcpy(&array[0], &kvsObject.byteBuffer[0], (numberElements * 1));
        }
    }

    return numberElements;
}

void KVStore::registerHandler(std::string key,
        kvstore::Callback callbackHandle) {

    kvstore::SignalPtr keySignal;

    if (signalLookup.count(key) > 0) {
        keySignal = signalLookup[key];
    } else {
        keySignal = kvstore::SignalPtr(new kvstore::Signal());
        signalLookup[key] = keySignal;
    }

    keySignal->connect(callbackHandle);
}

void KVStore::disconnectHandlers(std::string key) {

    if (signalLookup.count(key) > 0) {
        signalLookup[key]->disconnect_all_slots();
    }
}

void KVStore::runPublishThread() {

    Sender sender(io_service_p,
            boost::asio::ip::address::from_string(
                    appConfig.getMulticastAddress()),
            appConfig.getMulticastPort());
    io_service_p.run();

    while (!shutdownRequested) {

        publishBuffer = "";
        sendPublishBuffer = false;

        buildPublishBuffer();

        if (sendPublishBuffer)
            sender.sendTo(publishBuffer);

        boost::this_thread::sleep(boost::posix_time::milliseconds(30));
    }

    publishThreadComplete = true;
}

void KVStore::buildPublishBuffer() {

    int size = pubQueue.size();

    if (size > 0) {

        int64_t milliseconds =
                boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();

        pubTransaction.Clear();

        pubTransaction.set_publisherid(publisherID);
        pubTransaction.set_timestamp(milliseconds);
        pubTransaction.set_action(kvstore_ns::DBASE_SET);
        pubTransaction.set_systembyteorder(systemByteOrder);

        for (int i = 0; i < size; i++) {

            KVSObject kvsObject;

            if (pubQueue.front(kvsObject)) {

                kvstore_ns::KeyValueSet *keyValueSet =
                        pubTransaction.add_keyvalueset();

                keyValueSet->set_key(kvsObject.key.c_str());
                keyValueSet->set_typeinfo(
                        (kvstore_ns::TYPE_Info) kvsObject.typeInfo);
                keyValueSet->set_numberelements(kvsObject.numberElements);
                if (kvsObject.numberElements > 0) {
                    keyValueSet->set_bytebuffer(&kvsObject.byteBuffer[0],
                        kvsObject.byteBuffer.size());
                }
            }
        }

        pubTransaction.SerializeToString(&publishBuffer);

        sendPublishBuffer = true;
    }
}

void KVStore::runReceiveThread() {

    Receiver receiver(io_service_r,
            boost::asio::ip::address::from_string(appConfig.getListenAddress()),
            boost::asio::ip::address::from_string(
                    appConfig.getMulticastAddress()),
            appConfig.getMulticastPort());
    receiver.setCallback(
            boost::bind(&KVStore::processRcvCallback, this, _1, _2));
    io_service_r.run();

    while (!shutdownRequested) {

        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }

    receiveThreadComplete = true;
}

void KVStore::processRcvCallback(char *data, int numBytes) {

    bool parseSuccess = rcvTransaction.ParseFromArray(data, numBytes);

    if (parseSuccess) {

        // Only update the dataStore from transactions originating
        // from other kvstore publishers
        if ((rcvTransaction.action() == kvstore_ns::DBASE_SET)
                && rcvTransaction.publisherid() != publisherID) {

            for (int j = 0; j < rcvTransaction.keyvalueset_size(); j++) {

                kvstore_ns::KeyValueSet keyValueSet =
                        rcvTransaction.keyvalueset(j);
                KVSObject kvsObject;

                int bufferLength = keyValueSet.bytebuffer().length();

                kvsObject.key = keyValueSet.key();
                kvsObject.typeInfo = keyValueSet.typeinfo();
                kvsObject.numberElements = keyValueSet.numberelements();
                if (kvsObject.numberElements > 0) {
                    kvsObject.byteBuffer.resize(bufferLength);
                    memcpy(&kvsObject.byteBuffer[0],
                        keyValueSet.bytebuffer().c_str(), bufferLength);
                }

                // Perform byte swapping (if required)
                if (rcvTransaction.systembyteorder() != systemByteOrder) {

                    int8_t* value_ptr = (int8_t *) &kvsObject.byteBuffer[0];

                    switch (kvsObject.typeInfo) {

                    case kvstore_ns::TYPE_INT32:
                    case kvstore_ns::TYPE_FLOAT:

                        if (kvsObject.numberElements == 1)
                            ByteSwapper::swapFourBytes(value_ptr);
                        else
                            ByteSwapper::swapFourByteArray(value_ptr,
                                    kvsObject.numberElements);
                        break;

                    case kvstore_ns::TYPE_INT64:
                    case kvstore_ns::TYPE_DOUBLE:
                        if (kvsObject.numberElements == 1)
                            ByteSwapper::swapEightBytes(value_ptr);
                        else
                            ByteSwapper::swapEightByteArray(value_ptr,
                                    kvsObject.numberElements);
                        break;

                    default:
                        break;
                    }
                }

                mutex.lock();

                dataStore[kvsObject.key] = kvsObject;

                if (appConfig.getProcessCallbacks()) {

                    if (signalLookup.count(kvsObject.key) > 0) {

                        signalLookup[kvsObject.key]->operator()();
                    }
                }

                mutex.unlock();
            }
        }
    }
}

