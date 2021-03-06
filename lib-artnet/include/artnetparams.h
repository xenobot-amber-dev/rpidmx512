/**
 * @file artnetparams.h
 *
 */
/**
 * Art-Net Designed by and Copyright Artistic Licence Holdings Ltd.
 *
 * Art-Net 3 Protocol Release V1.4 Document Revision 1.4bk 23/1/2016
 *
 */
/* Copyright (C) 2016, 2017 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef ARTNETPARAMS_H_
#define ARTNETPARAMS_H_

#include <stdint.h>
#include <stdbool.h>

#include "artnetnode.h"
#include "common.h"

enum  tOutputType {
	OUTPUT_TYPE_DMX,
	OUTPUT_TYPE_SPI,
	OUTPUT_TYPE_MONITOR
};

class ArtNetParams {
public:
	ArtNetParams(void);
	~ArtNetParams(void);

	bool Load(void);

	const uint8_t GetNet(void);
	const uint8_t GetSubnet(void);
	const uint8_t GetUniverse(void);
	const uint8_t *GetShortName(void);
	const uint8_t *GetLongName(void);
	const tOutputType GetOutputType(void);
	const uint8_t *GetManufacturerId(void);

	const bool IsUseTimeCode(void);
	const bool IsUseTimeSync(void);
	const bool IsRdm(void);
	const bool IsRdmDiscovery(void);

	void Set(ArtNetNode *);
#if defined(__linux__) || defined (__CYGWIN__)
	void Dump(void);
#endif

private:
	bool isMaskSet(uint16_t);
	const uint16_t HexUint16(const char *);

public:
    static void staticCallbackFunction(void *p, const char *s);

private:
    void callbackFunction(const char *s);

private:
    uint32_t m_bSetList;
    uint8_t m_nNet;
    uint8_t m_nSubnet;
    uint8_t m_nUniverse;
    tOutputType m_tOutputType;
    bool m_bUseTimeCode;
    bool m_bUseTimeSync;
    bool m_bEnableRdm;
    bool m_bRdmDiscovery;
    uint8_t m_aShortName[ARTNET_SHORT_NAME_LENGTH];
	uint8_t m_aLongName[ARTNET_LONG_NAME_LENGTH];
	uint8_t m_aManufacturerId[2];
	uint8_t m_aOemValue[2];
};

#endif /* ARTNETPARAMS_H_ */
