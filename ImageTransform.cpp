#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
  for(unsigned x = 0; x < min(firstImage.width(),secondImage.width()); x++){
	for(unsigned y = 0; y < min(firstImage.height(),secondImage.height()); y++){
		
  	HSLAPixel & pixel1 = firstImage.getPixel(x,y);
  	HSLAPixel & pixel2 = secondImage.getPixel(x,y);
		if(pixel2.l == 1){
			pixel1.l += 0.2;
		}
	}
  }
  return firstImage;
}