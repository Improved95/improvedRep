#include "Streams.h"
#include "Exceptions.h"
#include <vector>
#include <cstring>
#include "functional"
using std::function;
using std::cerr;
using std::endl;
using std::vector;

int BinaryStreamIn::openFile(const string &fileName) {
    int r;
    this->stream.open(fileName, std::ios::in | std::ios::binary);
    r = checkFileOpen(fileName);
    return r;
}


int BinaryStreamOut::openFile(const string &fileName) {
    this->stream.open(fileName, std::ios::out | std::ios::binary);
    return checkFileOpen(fileName);
}

int StreamIn::openFile(const std::string &fileName) {
    this->stream.open(fileName, std::ios::in);
    return checkFileOpen(fileName);
}

int Stream::checkFileOpen(const string &fileName) {
    try {
        if (!this->stream.is_open()) {
            throw FileNotOpenException(fileName);
        }
    } catch (FileNotOpenException &ex) {
        cerr << ex.ex_what() << endl;
        return ex.getErrorCode();
    }
    return 0;
}

char * BinaryStreamIn::samplesInOneSecond = nullptr;
char *BinaryStreamIn::getSamplesInOneSecond(const size_t second, const size_t frequency,
                                            const size_t bitsPerSample) {

    this->stream.read(samplesInOneSecond, frequency * (bitsPerSample / BITS_PER_BYTE));

    return samplesInOneSecond;
}

int BinaryStreamIn::parseMetadataInWavFile(const size_t frequency, const size_t bitsPerSample,
                                           const size_t numberOfChannels, const size_t compressingCode) {
    
    
    return 0;
}
