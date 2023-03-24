#include "../uiuc/catch/catch.hpp"

#include "../ImageTransform.h"
#include "../uiuc/PNG.h"
#include "../uiuc/HSLAPixel.h"

PNG createRainbowPNG() {
  PNG png(360, 100);
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      pixel.h = x;
      pixel.s = y / 100.0;
      pixel.l = 0.5;
    }
  }
  return png;
}

PNG createWatermark() {
	PNG png(360, 100);
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      if (y >= 10 && y <= 30) { pixel.l = 1; }
      else                    { pixel.l = 0; }
    }
  }
  return png;
}


TEST_CASE("watermark", "[weight=1]") {
  PNG png = createRainbowPNG();
  PNG wm = createWatermark();

  PNG result = watermark(png, wm);

  SECTION("Pixels without watermark should be unchanged") {
    REQUIRE( png.getPixel(100, 50).l == result.getPixel(100, 50).l );
    REQUIRE( png.getPixel(200, 80).l == result.getPixel(200, 80).l );
  }

  SECTION("Pixels with watermark should be changed") {
    REQUIRE( png.getPixel(100, 15).l + 0.2 == result.getPixel(100, 15).l );
    REQUIRE( png.getPixel(200, 25).l + 0.2 == result.getPixel(200, 25).l );
  }
}
