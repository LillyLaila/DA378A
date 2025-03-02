#include <cstring>
#include <cstdint>
#include <cassert>

// Quake's inverse square root, adapted for C++.
// 
// https://en.wikipedia.org/wiki/Fast_inverse_square_root
// https://stackoverflow.com/a/17790026/4484477
//
float Q_rsqrt(float x)
{
  float xhalf = 0.5f*x;
  uint32_t i;
  assert(sizeof(x) == sizeof(i));
  std::memcpy(&i, &x, sizeof(i));
  i = 0x5f375a86 - (i>>1);
  std::memcpy(&x, &i, sizeof(i));
  x = x*(1.5f - xhalf*x*x);
  return x;
}
