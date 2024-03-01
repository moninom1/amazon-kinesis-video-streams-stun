
#ifndef STUN_DESERIALIZER_H
#define STUN_DESERIALIZER_H

#include "stun_data_types.h"

StunResult_t StunDeserializer_Init( StunContext_t * pCtx,
                                    const uint8_t * pStunMessage,
                                    size_t stunMessageLength,
                                    StunHeader_t * pStunHeader );

StunResult_t StunDeserializer_GetNextAttribute( StunContext_t * pCtx,
                                                StunAttribute_t * pAttribute );

StunResult_t StunDeserializer_ParseAttributePriority( const StunContext_t * pCtx,
                                                      const StunAttribute_t * pAttribute,
                                                      uint32_t * pPriority );

StunResult_t StunDeserializer_ParseAttributeFingerpint( const StunContext_t * pCtx,
                                                        const StunAttribute_t * pAttribute,
                                                        uint32_t * crc32Fingerprint );

StunResult_t StunDeserializer_ParseAttributeLifetime( const StunContext_t * pCtx,
                                                      const StunAttribute_t * pAttribute,
                                                      uint32_t * lifetime );

StunResult_t StunDeserializer_ParseAttributeChangeRequest( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           uint32_t * pChangeFlag );

StunResult_t StunDeserializer_ParseAttributeIceControlled( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           uint64_t * pTieBreaker );

StunResult_t StunDeserializer_ParseAttributeIceControlling( const StunContext_t * pCtx,
                                                            const StunAttribute_t * pAttribute,
                                                            uint64_t * pTieBreaker );

StunResult_t StunDeserializer_ParseAttributeUsername( const StunAttribute_t * pAttribute,
                                                      const char ** ppUsername,
                                                      uint16_t * pUsernameLength );

StunResult_t StunDeserializer_ParseAttributeData( const StunAttribute_t * pAttribute,
                                                  const char ** ppData,
                                                  uint16_t * pDataLength );

StunResult_t StunDeserializer_ParseAttributeRealm( const StunAttribute_t * pAttribute,
                                                   const char ** ppRealm,
                                                   uint16_t * pRealmLength );

StunResult_t StunDeserializer_ParseAttributeNonce( const StunAttribute_t * pAttribute,
                                                   const char ** ppNonce,
                                                   uint16_t * pNonceLength );

StunResult_t StunDeserializer_ParseAttributeRequestedTransport( const StunAttribute_t * pAttribute,
                                                                const char ** ppRequestedTransport,
                                                                uint16_t * pRequestedTransportLength );

StunResult_t StunDeserializer_ParseAttributeIntegrity( const StunAttribute_t * pAttribute,
                                                       const char ** ppIntegrity,
                                                       uint16_t * pIntegrityLength );

StunResult_t StunDeserializer_ParseAttributeAddress( const StunContext_t * pCtx,
                                                     const StunAttribute_t * pAttribute,
                                                     StunAttributeAddress_t * pStunMappedAddress,
                                                     uint8_t * pTransactionId,
                                                     StunAttributeType_t attributeType );

StunResult_t StunDeserializer_ParseAttributeMappedAddress( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           StunAttributeAddress_t * pStunMappedAddress,
                                                           uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeResponseAddress( const StunContext_t * pCtx,
                                                             const StunAttribute_t * pAttribute,
                                                             StunAttributeAddress_t * pStunMappedAddress,
                                                             uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeSourceAddress( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           StunAttributeAddress_t * pStunMappedAddress,
                                                           uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeChangedAddress( const StunContext_t * pCtx,
                                                            const StunAttribute_t * pAttribute,
                                                            StunAttributeAddress_t * pStunMappedAddress,
                                                            uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeReflectedFrom( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           StunAttributeAddress_t * pStunMappedAddress,
                                                           uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeXORMappedAddress( const StunContext_t * pCtx,
                                                              const StunAttribute_t * pAttribute,
                                                              StunAttributeAddress_t * pStunMappedAddress,
                                                              uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeXORPeerAddress( const StunContext_t * pCtx,
                                                            const StunAttribute_t * pAttribute,
                                                            StunAttributeAddress_t * pStunMappedAddress,
                                                            uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeXORRelayedAddress( const StunContext_t * pCtx,
                                                               const StunAttribute_t * pAttribute,
                                                               StunAttributeAddress_t * pStunMappedAddress,
                                                               uint8_t * pTransactionId );

StunResult_t StunDeserializer_ParseAttributeErrorCode( const StunAttribute_t * pAttribute,
                                                       uint16_t * errorCode,
                                                       char ** errorPhrase );

StunResult_t StunDeserializer_ParseAttributeChannelNumber( const StunContext_t * pCtx,
                                                           const StunAttribute_t * pAttribute,
                                                           uint16_t * channelNumber,
                                                           StunAttributeType_t attributeType );

StunResult_t StunDeserializer_ParseAttributeDontFragment( StunContext_t * pCtx,
                                                          const StunAttribute_t * pAttribute,
                                                          StunAttributeType_t attributeType );

StunResult_t StunDeserializer_ParseAttributeUseCandidate( StunContext_t * pCtx,
                                                          const StunAttribute_t * pAttribute,
                                                          StunAttributeType_t attributeType );

StunResult_t StunDeserializer_IsFlagAttributeFound( const StunContext_t * pCtx,
                                                    StunAttributeType_t attributeType,
                                                    uint16_t * attrFound );

StunResult_t StunDeserializer_GetIntegrityBuffer( StunContext_t * pCtx,
                                                  char ** ppStunMessage,
                                                  uint16_t * pStunMessageLength );

StunResult_t StunDeserializer_GetFingerprintBuffer( StunContext_t * pCtx,
                                                    char ** ppStunMessage,
                                                    uint16_t * pStunMessageLength );

StunResult_t StunDeserializer_FindAttribute( StunContext_t * pCtx,
                                             char ** ppAttribute,
                                             StunAttributeType_t attributeType );

StunResult_t StunDeserializer_UpdateAttributeNonce( const StunContext_t * pCtx,
                                                    char * pAttribute,
                                                    const char * pNonce,
                                                    uint16_t nonceLength );
#endif /* STUN_DESERIALIZER_H */
