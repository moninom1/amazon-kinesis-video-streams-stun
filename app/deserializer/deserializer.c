/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Deserializer includes. */
#include "stun_deserializer.h"

uint8_t stunMessage[] = { 0x00, 0x01, 0x00, 0x64, 0x21, 0x12, 0xa4, 0x42, 0xb7, 0xe7,
                          0xa7, 0x01, 0xbc, 0x34, 0xd6, 0x86, 0xfa, 0x87, 0xdf, 0xae,
                          0x00, 0x06, 0x00, 0x11, 0x36, 0x61, 0x30, 0x35, 0x66, 0x38, 0x34, 0x38,
                          0x3a, 0x38, 0x61, 0x63, 0x33, 0x65, 0x39, 0x30, 0x32, 0x00, 0x00, 0x00,
                          0x00, 0x24, 0x00, 0x04, 0x7e, 0x7f, 0x00, 0xff,
                          0x00, 0x01, 0x00, 0x14, 0x00, 0x02, 0x55, 0x80, 0x20, 0x01, 0x0d, 0xb8,
                          0x12, 0x34, 0x56, 0x78, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                          0x00, 0x20, 0x00, 0x14, 0x00, 0x02, 0xa1, 0x47, 0x01, 0x13, 0xa9, 0xfa,
                          0xa5, 0xd3, 0xf1, 0x79, 0xbc, 0x25, 0xf4, 0xb5, 0xbe, 0xd2, 0xb9, 0xd9,
                          0x00, 0x09, 0x00, 0x10, 0x00, 0x00, 0x04, 0x03, 0x46, 0x6f, 0x72, 0x62, 0x69, 0x64, 0x64, 0x65, 0x6e, 0x20, 0x49, 0x50  };

int main( void )
{
    StunResult_t result;
    StunContext_t stunContext;
    StunHeader_t header;
    StunAttribute_t stunAttribute;
    StunAttributeAddress_t stunMappedAddress;

    /* Initialize STUN context for deserializing. */
    result = StunDeserializer_Init( &( stunContext ),
                                    &( stunMessage[ 0 ] ),
                                    sizeof( stunMessage ),
                                    &( header )  );

    if( result == STUN_RESULT_OK )
    {
        printf( "Stun Message Type = %d\n", header.messageType );
        printf( "Transaction ID: " );
        for( int i = 0; i < STUN_HEADER_TRANSACTION_ID_LENGTH; i++ )
        {
            printf( "0x%02x ", header.transactionId[ i ] );
        }
        printf( "\n" );
    }

    while( result == STUN_RESULT_OK )
    {
        result = StunDeserializer_GetNextAttribute( &( stunContext ),
                                                    &( stunAttribute ) );

        if( result == STUN_RESULT_OK )
        {
            switch( stunAttribute.attributeType )
            {
                case STUN_ATTRIBUTE_TYPE_USERNAME:
                {
                    const char * pUsername;
                    uint16_t usernameLength;

                    result = StunDeserializer_ParseAttributeUsername( &( stunAttribute ),
                                                                        &( pUsername ),
                                                                        &( usernameLength ) );

                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Username: %.*s\n", usernameLength, pUsername );
                    }
                }
                break;

                case STUN_ATTRIBUTE_TYPE_PRIORITY:
                {
                    uint32_t priority;

                    result = StunDeserializer_ParseAttributePriority( &( stunAttribute ),
                                                                      &( priority ) );

                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Priority: 0x%0X\n", priority );
                    }
                }
                break;

                case STUN_ATTRIBUTE_TYPE_FINGERPRINT:
                {
                    uint32_t crc32Fingerprint;

                    result = StunDeserializer_ParseAttributeFingerpint( &( stunAttribute ),
                                                                        &( crc32Fingerprint ) );

                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Fingerprint: 0x%0X\n", crc32Fingerprint );
                    }
                }
                break;

                case STUN_ATTRIBUTE_TYPE_LIFETIME:
                {
                    uint32_t lifetime;

                    result = StunDeserializer_ParseAttributeLifetime( &( stunAttribute ),
                                                                      &( lifetime ) );

                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Lifetime: 0x%0X\n", lifetime );
                    }
                }
                break;

                case STUN_ATTRIBUTE_TYPE_MAPPED_ADDRESS:
                {
                    result = StunDeserializer_ParseAttributeMappedAddress( &stunAttribute,
                                                                           &stunMappedAddress );
                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Family %x \n", stunMappedAddress.family );
                        printf( "Port %d \nIPV6 address ", stunMappedAddress.port );
                        if( stunMappedAddress.family == STUN_ADDRESS_IPv6 )
                        {
                            for(int i=0;i<16;i++)
                            {
                                printf( "%x ",stunMappedAddress.address[i] );
                            }
                            printf( "\n" );
                        }
                    }

                }
                break;

                case STUN_ATTRIBUTE_TYPE_XOR_MAPPED_ADDRESS:
                {
                    memset( &stunMappedAddress, 0, sizeof( StunAttributeAddress_t ) );
                    result = StunDeserializer_ParseAttributeXORMappedAddress( &stunAttribute,
                                                                              &stunMappedAddress,
                                                                              header.transactionId );
                    if( result == STUN_RESULT_OK )
                    {
                        printf( "Family %x \n", stunMappedAddress.family );
                        printf( "Port %d \nIPV6 address ", stunMappedAddress.port );
                        if( stunMappedAddress.family == STUN_ADDRESS_IPv6 )
                        {
                            for(int i=0;i<16;i++)
                            {
                                printf( "%x ",stunMappedAddress.address[i] );
                            }
                            printf( "\n" );
                        }
                    }
                }
                break;

                case STUN_ATTRIBUTE_TYPE_ERROR_CODE:
                {
                    uint16_t errorCode;
                    uint8_t *errorPhrase;

                    result = StunDeserializer_ParseAttributeErrorCode( &stunAttribute,
                                                                       &errorCode,
                                                                       &errorPhrase );
                    if( result == STUN_RESULT_OK )
                    {
                        printf( "ErrorCode %d \n", errorCode );
                        printf( "ErrorPhrase %s \n", errorPhrase );
                    }
                }
                break;

                default:
                    break;
            }
        }
    }

    return 0;
}
