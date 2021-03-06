/**
 * @file xxtea.h
 * @brief XXTEA加密算法
 * Licensed under the MIT licenses.
 *
 * @version 1.0
 * @author OWenT
 * @date 2016.08.09
 *
 * @see https://en.wikipedia.org/wiki/XXTEA
 * @history
 *
 *
 */

#ifndef _UTIL_ALGORITHM_XXTEA_H_
#define _UTIL_ALGORITHM_XXTEA_H_

#pragma once

#include <stddef.h>

#if defined(__FreeBSD__) && __FreeBSD__ < 5
/* FreeBSD 4 doesn't have stdint.h file */
#include <inttypes.h>
#else
#include <stdint.h>
#endif

namespace util {
    typedef struct { uint32_t data[4]; } xxtea_key;

    void xxtea_setup(xxtea_key *k, const unsigned char filled[4 * sizeof(uint32_t)]);

    /**
     * @brief encrypt data use xxtea
     * @param buffer buffer address, must padding to uint32_t
     * @param len buffer size, must padding to uint32_t, can not be greater than 2^34
     */
    void xxtea_encrypt(const xxtea_key *key, void *buffer, size_t len);

    /**
     * @brief decrypt data use xxtea
     * @param buffer buffer address, must padding to uint32_t
     * @param len buffer size, must padding to uint32_t, can not be greater than 2^34
     */
    void xxtea_decrypt(const xxtea_key *key, void *buffer, size_t len);
}

#endif