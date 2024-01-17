/* Noah Nininger
 * CPSC 2311
 * Widman
 * 06/25/2023 (extended to 06/25)
 */

#include <stdio.h>
  
int main()
{
  int sign, exp, fraction, significand;
  int i;
  float f;
  float prev = 0;

  for (i = 0; i < 256; i++)
  {
    /* begin your code */
    sign = (i >> 7) & 0x01;
    exp = (i >> 3) & 0x0F;
    fraction = i & 0x07;

    if (exp == 0)
      { exp = 1; }
    else { exp -= 8; }

    significand = fraction << 21;
    f = (sign << 31) | (exp << 23) | significand;
    /* end your code */

    printf ("%02x => %08x = %+11.6f (spacing = %+11.6f)\n",
            i, *(int*) &f, f, prev-f);
    prev = f;
  }

  return 0;
}
