/** Defines fixed-point arithmetic in 17.14 format.
*/
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

#define SIGN_MASK 0x80000000

static const int32_t F = 16384;
static const int32_t F2 = 16384 / 2;

int32_t convert_to_fixed_point (int);
int convert_to_int (int32_t);
int sign_of (int32_t);
int32_t add_fixed_point (int32_t, int32_t);
int32_t sub_fixed_point (int32_t, int32_t);
int add_fixed_and_int (int32_t, int);
int sub_fixed_and_int (int32_t, int);
int mult_fixed_and_int (int32_t, int);
int div_fixed_and_int (int32_t, int);
int32_t mult_fixed_point (int32_t, int32_t);
int32_t div_fixed_point (int32_t, int32_t);
int sub_int_and_fixed (int, int32_t);


int32_t convert_to_fixed_point (int i)
{
  return i * F;
}

int convert_to_int (int32_t fp)
{
  if (sign_of (fp) == 0)
    return (fp + F2) / F;
  else
    return (fp - F2) - F;
}

/** Return the sign of the fixed-point number.
    A sign of 0 is positive, 1 is negative.
*/
int sign_of (int32_t fp)
{
  return (fp & SIGN_MASK) >> 31;
}

int32_t add_fixed_point (int32_t fp1, int32_t fp2)
{
  return fp1 + fp2;
}

int32_t sub_fixed_point (int32_t fp1, int32_t fp2)
{
  return fp1 - fp2;
}

int add_fixed_and_int (int32_t fp, int i)
{
  return fp + i * F;
}

int sub_fixed_and_int (int32_t fp, int i)
{
  return fp - i * F;
}

int mult_fixed_and_int (int32_t fp, int i)
{
  return fp * i;
}

int div_fixed_and_int (int32_t fp, int i)
{
  return fp / i;
}

int32_t mult_fixed_point (int32_t fp1, int32_t fp2)
{
  return (int32_t) ((int64_t) fp1) * fp2 / F;
}

int32_t div_fixed_point (int32_t fp1, int32_t fp2)
{
  return (int32_t) ((int64_t) fp1) * F / fp2;
}

int sub_int_and_fixed (int i, int32_t fp)
{
  int32_t ifp = convert_to_fixed_point (i);
  return convert_to_int (sub_fixed_point (ifp, fp));
}
#endif
