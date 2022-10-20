
#if defined(__arm__) || defined(__aarch64__)
#define SIMDE_ENABLE_NATIVE_ALIASES
#include "simde/x86/sse2.h"
#else
#include <emmintrin.h>
#endif

#include <iostream>

void printM128I0(__m128i v, const char* pfx)
{
   std::cout << pfx << " ";
   auto sv = _mm_shuffle_epi32(v, _MM_SHUFFLE(0,0,0,0));
   auto iv = _mm_cvtsi128_si32(sv);
   std::cout << std::hex << iv << " "; 

   sv = _mm_shuffle_epi32(v, _MM_SHUFFLE(1,1,1,1));
   iv = _mm_cvtsi128_si32(sv);
   std::cout << std::hex << iv << std::endl;
}

int main(int argc, char **argv)
{
    __m128i three = _mm_set1_epi32(3);
    auto six = _mm_add_epi32(three, three);
    printM128I0(three, "Three + Three = ");    

    __m128i oneI = _mm_set1_epi32(1);
    auto sh1 = _mm_slli_epi32(oneI, 2);
    printM128I0(sh1, "One Shifted Twice");

    int shift = 4;

#if 1 && (defined(__arm__) || defined(__aarch64__))
    auto shV = _mm_set1_epi32(shift);
    auto res = vshlq_s32(simde__m128i_to_neon_i32(oneI), vdupq_n_s32(shift));

    auto sh4 = simde__m128i_from_neon_i32(res);
#else
    auto sh4 = _mm_slli_epi32(oneI, shift);
#endif
    printM128I0(sh1, "One Shifted Four");
}

