#ifndef STUN_SERIALIZER_H
#define STUN_SERIALIZER_H

#include "stun_data_types.h"

StunResult_t StunSerializer_Init( StunSerializeContext_t * pCtx,
                                  uint8_t * pBuffer,
                                  size_t bufferLength,
                                  const StunHeader_t * pHeader );

StunResult_t StunSerializer_AddAttributeErrorCode( StunSerializeContext_t * pCtx,
                                                   uint16_t errorCode,
                                                   const uint8_t * pErrorPhrase,
                                                   uint16_t errorPhraseLength );

StunResult_t StunSerializer_AddAttributeChannelNumber( StunSerializeContext_t * pCtx,
                                                       uint16_t channelNumber );

StunResult_t StunSerializer_AddAttributeUseCandidate( StunSerializeContext_t * pCtx );

StunResult_t StunSerializer_AddAttributeDontFragment( StunSerializeContext_t * pCtx );

StunResult_t StunSerializer_AddAttributePriority( StunSerializeContext_t * pCtx,
                                                  uint32_t priority );

StunResult_t StunSerializer_AddAttributeFingerprint( StunSerializeContext_t * pCtx,
                                                     uint32_t crc32Fingerprint );

StunResult_t StunSerializer_AddAttributeLifetime( StunSerializeContext_t * pCtx,
                                                  uint32_t lifetime );

StunResult_t StunSerializer_AddAttributeChangeRequest( StunSerializeContext_t * pCtx,
                                                       uint32_t changeFlag );

StunResult_t StunSerializer_AddAttributeIceControlled( StunSerializeContext_t * pCtx,
                                                       uint64_t tieBreaker );

StunResult_t StunSerializer_AddAttributeIceControlling( StunSerializeContext_t * pCtx,
                                                        uint64_t tieBreaker );

StunResult_t StunSerializer_AddAttributeUsername( StunSerializeContext_t * pCtx,
                                                  const uint8_t * pUsername,
                                                  uint16_t usernameLength );

StunResult_t StunSerializer_AddAttributeData( StunSerializeContext_t * pCtx,
                                              const uint8_t * pData,
                                              uint16_t dataLength );

StunResult_t StunSerializer_AddAttributeRealm( StunSerializeContext_t * pCtx,
                                               const uint8_t * pRealm,
                                               uint16_t realmLength );

StunResult_t StunSerializer_AddAttributeNonce( StunSerializeContext_t * pCtx,
                                               const uint8_t * pNonce,
                                               uint16_t nonceLength );

StunResult_t StunSerializer_AddAttributeRequestedTransport( StunSerializeContext_t * pCtx,
                                                            const uint8_t * pRequestedTransport,
                                                            uint16_t requestedTransportLength );

StunResult_t StunSerializer_AddAttributeIntegrity( StunSerializeContext_t * pCtx,
                                                   const uint8_t * pIntegrity,
                                                   uint16_t integrityLength );

StunResult_t StunSerializer_AddAttributeAddress( StunSerializeContext_t * pCtx,
                                                 const StunAttributeAddress_t * pAddress,
                                                 StunAttributeType_t attributeType );

StunResult_t StunSerializer_AddAttributeMappedAddress( StunSerializeContext_t * pCtx,
                                                       const StunAttributeAddress_t * pMappedAddress );

StunResult_t StunSerializer_AddAttributeResponseAddress( StunSerializeContext_t * pCtx,
                                                         const StunAttributeAddress_t * pResponseAddress );

StunResult_t StunSerializer_AddAttributeSourceAddress( StunSerializeContext_t * pCtx,
                                                       const StunAttributeAddress_t * pSourceAddress );

StunResult_t StunSerializer_AddAttributeChangedAddress( StunSerializeContext_t * pCtx,
                                                        const StunAttributeAddress_t * pChangedAddress );

StunResult_t StunSerializer_AddAttributeChangedReflectedFrom( StunSerializeContext_t * pCtx,
                                                              const StunAttributeAddress_t * pReflectedFromAddress );

StunResult_t StunSerializer_AddAttributeXorMappedAddress( StunSerializeContext_t * pCtx,
                                                          const StunAttributeAddress_t * pMappedAddress );

StunResult_t StunSerializer_AddAttributeXorPeerAddress( StunSerializeContext_t * pCtx,
                                                        const StunAttributeAddress_t * pPeerAddress );

StunResult_t StunSerializer_AddAttributeXorRelayedAddress( StunSerializeContext_t * pCtx,
                                                           const StunAttributeAddress_t * pRelayedAddress );

StunResult_t StunSerializer_GetIntegrityBuffer( StunSerializeContext_t * pCtx,
                                                uint8_t ** ppStunMessage,
                                                uint16_t * pStunMessageLength );

StunResult_t StunSerializer_GetFingerprintBuffer( StunSerializeContext_t * pCtx,
                                                  uint8_t ** ppStunMessage,
                                                  uint16_t * pStunMessageLength );

StunResult_t StunSerializer_Finalize( StunSerializeContext_t * pCtx,
                                      size_t * pStunMessageLength );

#endif /* STUN_SERIALIZER_H */
