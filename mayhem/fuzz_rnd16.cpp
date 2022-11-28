#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" uint16_t rnd16(uint32_t *p_seed);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint32_t p_seed = provider.ConsumeIntegral<uint32_t>();
    rnd16(&p_seed);

    return 0;
}