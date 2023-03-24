#include "ImageTransform.h"
#include "uiuc/PNG.h"

int main() {
  uiuc::PNG img, watermarkImg, result;

  img.readFromFile("alma.png");
  watermarkImg.readFromFile("overlay.png");
  result = watermark(img, watermarkImg);
  result.writeToFile("out-watermark.png");
  
  return 0;
}
