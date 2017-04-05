#pragma once

///////////////////////////////////////////////////////////////////////////////////
// Image i/o using Greg Ward's RGBE reader and writer

#include <vector>

#include <assert.h>
#include <CryString/CryString.h>

class CImageProperties;
class ImageObject;

namespace ImageDDS
{
	ImageObject* LoadByUsingDDSLoader(const char* filenameRead, CImageProperties* pProps, string& res_specialInstructions);

	bool SaveByUsingDDSSaver(const char* filenameWrite, const CImageProperties* pProps, const ImageObject* pImageObject);
};
