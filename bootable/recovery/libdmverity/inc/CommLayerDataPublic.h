/**
* \file CommLayerDataPublic.h
* \brief Public defines and types. Distributes with API.
* \author Dmytro Podgornyi (d.podgornyi@samsung.com)
* \version 0.1
* \date Created Nov 21, 2013
* \par In Samsung Ukraine R&D Center (SURC) under a contract between
* \par LLC "Samsung Electronics Ukraine Company" (Kiev, Ukraine) and
* \par "Samsung Elecrtronics Co", Ltd (Seoul, Republic of Korea)
* \par Copyright: (c) Samsung Electronics Co, Ltd 2012. All rights reserved.
**/

#ifndef __COMMLAYERDATAPUBLIC_H_INCLUDED__
#define __COMMLAYERDATAPUBLIC_H_INCLUDED__

#include <stdint.h>

//// Key Blob field tags
#define RSA_CERT_TAG      (uint8_t) 0x01
#define IV_TAG            (uint8_t) 0x02
#define KEY_TAG           (uint8_t) 0x03
#define TL_NAME_TAG       (uint8_t) 0x04
#define ATTRS_TAG         (uint8_t) 0x05

//// ERROR CODES
#define NO_ERROR 0
#define UNSUPPORTED_CMD         ( int32_t ) -1
#define WRONG_DATA              ( int32_t ) -2
#define PLATFORM_INTERNAL_ERROR ( int32_t ) -3
#define SHA256_ERROR            ( int32_t ) -4
#define HMAC_ERROR              ( int32_t ) -5
#define SFS_READ_ERROR          ( int32_t ) -6
#define WRONG_RSA_CERT          ( int32_t ) -7
#define WRONG_PRIV_KEY          ( int32_t ) -8
#define NO_KEY_ERROR            ( int32_t ) -9
#define WRITE_KEY_ERROR         ( int32_t ) -10
#define READ_KEY_ERROR          ( int32_t ) -11
#define WRITE_SYMM_KEY_ERROR    ( int32_t ) -12
#define INSTALL_SYMM_KEY_ERROR  ( int32_t ) -14
#define NOT_IMPLEMENTED         ( int32_t ) -127

//// KEY TYPES
typedef enum
{
    /* RSA key */
    APCS_KEY = 0x10,
    RSA_KEY = 0x10,
    /* Symmetric key */
    SYMM_KEY = 0x20,
    /* Elliptic key */
    EC_SK_KEY = 0x30,
} ProvAgentKeys_t;

//// Key Info struct
/* UID can be bigger than 52 bytes */
#define MAX_UID_SIZE (52 * 2)
#define MAX_SERVICE_NAME 8
#define MAX_SERIALNO_SIZE 32
#define MAX_MODEL_SIZE 32
#define MAX_DATE_SIZE 16
#define MAX_TID_SIZE 16
struct KeyInfo
{
    /* 52 is for backward compatibility
     * size of KeyInfo must be equal to the old value */
    uint8_t serviceName[52];
    /* device serial number */
    uint8_t serialno[MAX_SERIALNO_SIZE];
    /* model name, ex: SGH-I337 */
    uint8_t model[MAX_MODEL_SIZE];
    /* date */
    uint16_t year;
    uint8_t mon;
    uint8_t mday;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    /* key length in bits, default 2048 */
    uint32_t keyLen;
    /* 1 - crt rsa, 0 - without crt */
    uint32_t crt;
};

typedef enum
{
    TLV_EXPONENT = 1,
    TLV_ISSUER,
    TLV_HASH_ALGO,
    TLV_SUBJECT,
    TLV_KEYUSAGE,
    TLV_EXT_KEYUSAGE,
    /* Identifier of the start of a TLV buffer */
    TLV_START = 0xfe
} TlvTag_t;

#endif /* __COMMLAYERDATAPUBLIC_H_INCLUDED__ */
