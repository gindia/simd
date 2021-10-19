#include <stdio.h>
#include <stdlib.h>

#include <immintrin.h> // for AVX
// #include <nmmintrin.h> // for SSE4.2 -> up too 4 floating points

int main() {

#if 1
  __m128 a4 = _mm_setr_ps(1.0f, 1.0f, 1.0f, 1.0f);
  __m128 b4 = _mm_setr_ps(1.0f, 1.0f, 1.0f, 1.0f);

  __m128 sum4 = _mm_add_ps(a4, b4);

#if MSVC
  printf("-m128 -> %f, %f, %f, %f \n", sum4.m128_f32[0], sum4.m128_f32[1], sum4.m128_f32[2], sum4.m128_f32[3]);
#else
  printf("-m128 -> %f, %f, %f, %f \n", sum4[0], sum4[1], sum4[2], sum4[3]);
#endif /* End of compiler print */

#endif

#if 1
  __m256 a8 = {
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m256 b8 = {
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
  };

  __m256 sum8 = _mm256_add_ps(a8, b8);

// Pass the MSVC commpiler as a compiler flag.
#if MSVC
  printf(
    "- m256\n"
    "0) %f, %f, %f, %f\n"
    "1) %f, %f, %f, %f\n",
    sum8.m256_f32[0], sum8.m256_f32[1], sum8.m256_f32[2], sum8.m256_f32[3], 
    sum8.m256_f32[4], sum8.m256_f32[5], sum8.m256_f32[6], sum8.m256_f32[7]
  );
#else
  printf(
    "- m256\n"
    "0) %f, %f, %f, %f\n"
    "1) %f, %f, %f, %f\n",
     sum8[0], sum8[1], sum8[2], sum8[3], 
     sum8[4], sum8[5], sum8[6], sum8[7]
  );

#endif /* End of compiler print */

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

#if MSVC
  printf(
      "- m512\n"
      "0) %f, %f, %f, %f \n"
      "1) %f, %f, %f, %f \n"
      "2) %f, %f, %f, %f \n"
      "3) %f, %f, %f, %f \n"
      , sum16.m512_f32[0] , sum16.m512_f32[1], sum16.m512_f32[2],  sum16.m512_f32[3]
      , sum16.m512_f32[4] , sum16.m512_f32[5], sum16.m512_f32[6],  sum16.m512_f32[7]
      , sum16.m512_f32[8] , sum16.m512_f32[9], sum16.m512_f32[10], sum16.m512_f32[11]
      , sum16.m512_f32[12], sum16.m512_f32[13],sum16.m512_f32[14], sum16.m512_f32[15]
  );
#else
  printf(
      "- m512\n"
      "0) %f, %f, %f, %f \n"
      "1) %f, %f, %f, %f \n"
      "2) %f, %f, %f, %f \n"
      "3) %f, %f, %f, %f \n"
      , sum16[0], sum16[1], sum16[2], sum16[3]
      , sum16[4], sum16[5], sum16[6], sum16[7]
      , sum16[8], sum16[9], sum16[10], sum16[11]
      , sum16[12], sum16[13], sum16[14], sum16[15]
  );
#endif /* End of compiler print */
#endif

  exit(EXIT_SUCCESS);
}
