
/* 
 *                     The LLVM Compiler Infrastructure
 *
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 *
 */

typedef          long long di_int;
typedef unsigned long long du_int;
typedef      int si_int;
typedef unsigned su_int;

/* Returns: count of 1 bits */
int __popcountsi2(int a)
{
    int x = (int)a;
    x = x - ((x >> 1) & 0x55555555);
    /* Every 2 bits holds the sum of every pair of bits */
    x = ((x >> 2) & 0x33333333) + (x & 0x33333333);
    /* Every 4 bits holds the sum of every 4-set of bits (3 significant bits) */
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    /* Every 8 bits holds the sum of every 8-set of bits (4 significant bits) */
    x = (x + (x >> 16));
    /* The lower 16 bits hold two 8 bit sums (5 significant bits). */
    /*    Upper 16 bits are garbage */
    return (x + (x >> 8)) & 0x0000003F;  /* (6 significant bits) */
}

/* double to unsigned long long */
/* external/compiler-rt/lib/builtins/fixunsdfdi.c */
du_int __fixunsdfdi(double a)
{
    if (a <= 0.0) return 0;
    su_int high = a / 4294967296.f;               /* a / 0x1p32f; */
    su_int low = a - (double)high * 4294967296.f; /* high * 0x1p32f; */
    return ((du_int)high << 32) | low;
}

/* double to signed long long */
/* external/compiler-rt/lib/builtins/fixdfdi.c */
di_int __aeabi_d2lz(double a)
{
    if (a < 0.0) {
        return -__fixunsdfdi(-a);
    }
    return __fixunsdfdi(a);
}

/* for testing
int main()
{
    double x = 6434243343.141592653589793238;
    printf("%lld", __aeabi_d2lz(x));
    return 0;
}
*/
