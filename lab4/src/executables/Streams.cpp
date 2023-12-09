#include "Streams.h"
#include "Exceptions.h"
#include <vector>
#include "WavMetadataParse.h"
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

char * BinaryStreamIn::getNewSamplesInOneSecond() {
    this->stream.read(sampleBuffer, this->WAVheader->bytePerSample);
    return sampleBuffer;
}

char *BinaryStreamIn::getSamplesInOneSecond() {
    return sampleBuffer;
}

size_t BinaryStreamOut::t2 = 0;
size_t BinaryStreamOut::t3 = 0;
void BinaryStreamOut::pushInFile(char *data, const size_t dataSize) {
    this->stream.write(data, dataSize);
    t2 += 1;
    t3 += dataSize;
}
