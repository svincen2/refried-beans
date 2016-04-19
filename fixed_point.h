/** Defines fixed-point arithmetic in 17.14 format.
*/
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

#define SIGN_MASK 0x80000000

static const int F = 16384;
static const int F2 = 16384 / 2;

int convert_to_fixed_point (int);
int convert_to_int (int);
int sign_of (int);
int add_fixed_point (int, int);
int sub_fixed_point (int, int);
int add_fixed_and_int (int, int);
int sub_fixed_and_int (int, int);
int mult_fixed_and_int (int, int);
int div_fixed_and_int (int, int);
int mult_fixed_point (int, int);
int div_fixed_point (int, int);
int sub_int_and_fixed (int, int);


int convert_to_fixed_point (int i)
{
  return i * F;
}

int convert_to_int (int fp)
{
  if (sign_of (fp) == 0)
    return (fp + F2) / F;
  else
    return (fp - F2) / F;
}

/** Return the sign of the fixed-point number.
    A sign of 0 is positive, 1 is negative.
*/
int sign_of (int fp)
{
  return (fp & SIGN_MASK) >> 31;
}

int add_fixed_point (int fp1, int fp2)
{
  return fp1 + fp2;
}

int sub_fixed_point (int fp1, int fp2)
{
  return fp1 - fp2;
}

int add_fixed_and_int (int fp, int i)
{
  return fp + i * F;
}

int sub_fixed_and_int (int fp, int i)
{
  return fp - i * F;
}

int mult_fixed_and_int (int fp, int i)
{
  return fp * i;
}

int div_fixed_and_int (int fp, int i)
{
  return fp / i;
}

int mult_fixed_point (int fp1, int fp2)
{
  return ((int64_t) fp1) * fp2 / F;
}

int div_fixed_point (int fp1, int fp2)
{
  return ((int64_t) fp1) * F / fp2;
}

int sub_int_and_fixed (int i, int fp)
{
  int ifp = convert_to_fixed_point (i);
  return convert_to_int (sub_fixed_point (ifp, fp));
}
#endif
