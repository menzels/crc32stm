#ifndef CRC32_H
#define CRC32_H

#include <stddef.h>
#include <stdint.h>

class Crc32
{
    typedef struct {
        uint32_t init;
        uint32_t polynomial;
    } Config;

public:
    Crc32();
    Crc32(uint32_t init, uint32_t polynomial);

    void addData(const void* data, size_t length);

    uint32_t getHash(){return crc_;}

    void reset(){crc_ = cfg_.init;}

private:
    uint32_t crc_;
    uint32_t lookup_[16][256];
    Config cfg_;

    void generateLookup();
};

#endif // CRC32_H
