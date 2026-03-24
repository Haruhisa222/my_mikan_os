#include <stdint.h>
#include <stddef.h>

#include "frame_buffer_config.hpp"

struct pixelColor {
  uint8_t r, g, b;
};

//ピクセル描画用のインタフェース
class PixelWriter{
 public:
  PixelWriter(const FrameBufferConfig& config) : config_{config} {
  }
  virtual ~PixelWriter() = default;
  virtual void Write(int x, int y, const pixelColor& c) = 0

  protected:
   uint8_t* PixelAt(int x, int y) {
    return config_.frame_buffer + 4 * (config_.pixels_per_scan_line * y + x);
  }

  private:
   const FrameBufferConfig& config_;
};








/** WritePixelは指定した座標に1つの点を描画する
 * @retval 0   成功
 * @retval 非0 失敗
 */

// int WritePixel(const FrameBufferConfig& config, int x, int y, const pixelColor& c) {
//   const int pixel_position = config.pixels_per_scan_line * y + x;
//   if(config.pixel_format == kPixelRGBResv8BitPerColor) {
//     uint8_t* p = &config.frame_buffer[4 * pixel_position];
//     p[0] = c.r;
//     p[1] = c.g;
//     p[2] = c.b;
//   } else if(config.pixel_format == kPixelBGRResv8BitPerColor) {
//     uint8_t* p = &config.frame_buffer[4 * pixel_position];
//     p[0] = c.b;
//     p[1] = c.g;
//     p[2] = c.r;
//   } else {
//     return -1;
//   }
//   return 0;
// }

// //WritePixelを使って画面描画
// extern "C" void KernelMain(const FrameBufferConfig& frame_buffer_config) {
//   for (int x = 0; x < frame_buffer_config.horizontal_resolution; ++x) {
//     for (int y = 0; y < frame_buffer_config.vertical_resolution; ++y) {
//       WritePixel(frame_buffer_config, x, y, {255, 255, 255});
//     }
//   }
//   for (int x = 0; x < 200; ++x){
//     for (int y = 0; y < 200; ++y) {
//       WritePixel(frame_buffer_config, 100 + x, 100 + y, {0, 255, 0});
//     }
//   }
//   while (1) __asm__("hlt");

// }