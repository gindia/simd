#include <stdio.h>
#include <stdlib.h>

#include <immintrin.h> // for AVX
// #include <nmmintrin.h> // for SSE4.2 -> up too 4 floating points

int main() {

#if 0
  __m128 a4 = _mm_setr_ps(1.0f, 1.0f, 1.0f, 1.0f);
  __m128 b4 = _mm_setr_ps(1.0f, 1.0f, 1.0f, 1.0f);

  __m128 sum4 = _mm_add_ps(a4, b4);

  printf(" %f, %f, %f, %f ", sum4[0], sum4[1], sum4[2], sum4[3]);
#endif

#if 1
  __m256 a8 = {
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m256 b8 = {
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m256 sum8 = _mm256_add_ps(a8, b8);

  printf(" %f, %f, %f, %f "
         " %f, %f, %f, %f ",
         sum8[0], sum8[1], sum8[2], sum8[3], sum8[4], sum8[5], sum8[6],
         sum8[7]);

#endif

#if 0
  // check if ur porccessor supports AVX512 if so add -mavx512f flag to the compiler (clang / gcc)
  __m512 a16 = {
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m512 b16 = {
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m512 sum16 = _mm512_add_ps(a16, b16);

  printf(
      " %f, %f, %f, %f "
      " %f, %f, %f, %f "
      " %f, %f, %f, %f "
      " %f, %f, %f, %f "
      , sum16[0], sum16[1], sum16[2], sum16[3]
      , sum16[4], sum16[5], sum16[6], sum16[7]
      , sum16[8], sum16[9], sum16[10], sum16[11]
      , sum16[12], sum16[13], sum16[14], sum16[15]
  );
#endif

  exit(EXIT_SUCCESS);
}
