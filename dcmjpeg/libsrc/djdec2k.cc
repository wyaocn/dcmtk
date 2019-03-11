#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djdec2k.h"
#include "dcmtk/dcmjpeg/djcparam.h"
#include "dcmtk/dcmjpeg/djrplol.h"
#include "dcmtk/dcmjpeg/djdijp2k.h"
#include "dcmtk/dcmdata/dcpixseq.h"  /* for class DcmPixelSequence */


DJDecoderJP2k::DJDecoderJP2k()
: DJCodecDecoder()
{
}


DJDecoderJP2k::~DJDecoderJP2k()
{
}

E_TransferSyntax DJDecoderJP2k::supportedTransferSyntax() const
{
  return EXS_JPEG2000;
}

OFBool DJDecoderJP2k::isLosslessProcess() const
{
  return OFFalse;
}


DJDecoder *DJDecoderJP2k::createDecoderInstance(
    const DcmRepresentationParameter * /* toRepParam */,
    const DJCodecParameter *cp,
    Uint8 bitsPerSample,
    OFBool isYBR) const
{
	return new DJDecompressJP2k(*cp, isYBR);
}

// **************

DJDecoderJP2kLossLess::DJDecoderJP2kLossLess()
: DJCodecDecoder()
{
}


DJDecoderJP2kLossLess::~DJDecoderJP2kLossLess()
{
}

E_TransferSyntax DJDecoderJP2kLossLess::supportedTransferSyntax() const
{
  return EXS_JPEG2000LosslessOnly;
}

OFBool DJDecoderJP2kLossLess::isLosslessProcess() const
{
  return OFTrue;
}


DJDecoder *DJDecoderJP2kLossLess::createDecoderInstance(
    const DcmRepresentationParameter * /* toRepParam */,
    const DJCodecParameter *cp,
    Uint8 bitsPerSample,
    OFBool isYBR) const
{
	return new DJDecompressJP2k(*cp, isYBR);
}