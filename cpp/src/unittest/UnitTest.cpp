#include "KVStore.hpp"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <climits>
#include <stdint.h>
#include <float.h>

static bool shutdownThread = false;

#ifdef WIN32
#include <windows.h> 

BOOL WINAPI consoleHandler(DWORD signal) {

    if (signal == CTRL_C_EVENT)
    shutdownThread = true;

    return TRUE;
}
#elif UNIX

void sigint_handler(int sig) {

    shutdownThread = true;
}
#endif

void myCallback() {

    std::cout << "mycallback was called" << std::endl;
}

void myCallback2() {

    std::cout << "mycallback2 was called" << std::endl;
}

int main(int argc, char *argv[]) {

#ifdef WIN32
    SetConsoleCtrlHandler(consoleHandler, TRUE);
#elif UNIX
    signal(SIGINT, sigint_handler);
#endif

    KVStore* database = new KVStore();

    // ***********  Start of the value declarations ***********

    int32_t intTest1 = INT_MAX;

    int64_t longTest1 = 9223372036854775807;

    float floatTest1 = FLT_MAX;

    double doubleTest1 = DBL_MAX;

    bool boolTest1 = true;

    std::string stringTest1 = "this is a test from c++";

    int8_t bytesTest1[] = { 7, 8, 9 };

    // ***********  Start of the array declarations ***********

    int32_t intArrayTest1[] = { 500, 1000, 1500, 2000, INT_MIN, INT_MAX };

    int64_t longArrayTest1[] = { 4000, 6000, 8000, 10000 };

    float floatArrayTest1[] =
            { FLT_MIN, -2312.343, 83411.1423, 9211.41, FLT_MAX };

    double doubleArrayTest1[] = { DBL_MIN, -7312.52, -3411.1423, 611.41,
            98234.22, DBL_MAX };

    bool boolArrayTest1[] =
            { true, true, true, true, false, false, false, false };

    database->start();

    //database->registerHandler("king", boost::bind(&TestClass::handleChange, this));
    //database->registerHandler("macaroni", boost::bind(&myCallback));
    database->registerHandler("king", boost::bind(&myCallback));

    database->setInt32Value("king", intTest1);
    database->setInt64Value("emperor", longTest1);
    database->setFloatValue("chinstrap", floatTest1);
    database->setDoubleValue("gentoo", doubleTest1);
    database->setBoolValue("magellanic", boolTest1);
    database->setStringValue("humboldt", stringTest1);
    database->setByteBufferValue("galapagos", &bytesTest1[0], 3);
    database->setInt32Array("waitaha", intArrayTest1, 6);
    database->setInt64Array("fiordland", longArrayTest1, 4);
    database->setFloatArray("snares", floatArrayTest1, 5);
    database->setDoubleArray("royal", doubleArrayTest1, 6);
    database->setBoolArray("chatham", boolArrayTest1, 8);
    database->postEvent("macaroni");

    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

    while (true) {

        int bytesRead, numberElements;
        std::cout << std::endl;

        // ***********  Start of the value tests ***********

        int intRead;
        intRead = database->getInt32Value("king");
        std::cout << intRead << std::endl;

        int64_t longRead;
        longRead = database->getInt64Value("emperor");
        std::cout << longRead << std::endl;

        float floatRead;
        floatRead = database->getFloatValue("chinstrap");
        std::cout << floatRead << std::endl;

        double doubleRead;
        doubleRead = database->getDoubleValue("gentoo");
        std::cout << doubleRead << std::endl;

        bool boolRead;
        boolRead = database->getBoolValue("magellanic");
        std::cout << boolRead << std::endl;

        std::string stringRead;
        stringRead = database->getStringValue("humboldt");
        std::cout << stringRead << stringRead << std::endl;

        int8_t byteBuffer[10];
        bytesRead = database->getByteBufferValue("galapagos", &byteBuffer[0]);
        if (bytesRead > 0) {
            std::cout << "Byte Buffer Test - Read " << bytesRead << " bytes"
                    << std::endl;
            std::cout << "[";
            for (int i = 0; i < bytesRead; i++)
                std::cout << (int) byteBuffer[i] << " ";
            std::cout << "]" << std::endl;
        }

        // ***********  Start of the array tests ***********

        int32_t intArray[15];
        numberElements = database->getInt32Array("waitaha", intArray);
        if (numberElements > 0) {
            std::cout << "Int Array Test - Read " << numberElements
                    << " elements" << std::endl;
            std::cout << "[";
            for (int i = 0; i < numberElements; i++)
                std::cout << (int) intArray[i] << " ";
            std::cout << "]" << std::endl;
        }

        int64_t longArray[15];
        numberElements = database->getInt64Array("fiordland", longArray);
        if (numberElements > 0) {
            std::cout << "Long Array Test - Read " << numberElements
                    << " elements" << std::endl;
            std::cout << "[";
            for (int i = 0; i < numberElements; i++)
                std::cout << (long long) longArray[i] << " ";
            std::cout << "]" << std::endl;
        }

        float floatArray[15];
        numberElements = database->getFloatArray("snares", floatArray);
        if (numberElements > 0) {
            std::cout << "Float Array Test - Read " << numberElements
                    << " elements" << std::endl;
            std::cout << "[";
            for (int i = 0; i < numberElements; i++)
                std::cout << (float) floatArray[i] << " ";
            std::cout << "]" << std::endl;
        }

        double doubleArray[15];
        numberElements = database->getDoubleArray("royal", doubleArray);
        if (numberElements > 0) {
            std::cout << "Double Array Test - Read " << numberElements
                    << " elements" << std::endl;
            std::cout << "[";
            for (int i = 0; i < numberElements; i++)
                std::cout << (double) doubleArray[i] << " ";
            std::cout << "]" << std::endl;
        }

        bool boolArray[15];
        numberElements = database->getBoolArray("chatham", boolArray);
        if (numberElements > 0) {
            std::cout << "Bool Array Test - Read " << numberElements
                    << " elements" << std::endl;
            std::cout << "[";
            for (int i = 0; i < numberElements; i++)
                std::cout << (bool) boolArray[i] << " ";
            std::cout << "]" << std::endl;
        }

        if (shutdownThread) {
            database->shutdownReq();

            while (!database->threadsAreComplete())
                boost::this_thread::sleep(boost::posix_time::milliseconds(200));

            exit(0);
        }

        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    }

    return 0;
}
