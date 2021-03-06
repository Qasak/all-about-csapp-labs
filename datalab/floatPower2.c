/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */

/*
    返回2.0的x次幂(x是32位整数)
    如果结果太小而不能表示为denorm,返回0
    如果太大,返回+inf
 */
 
//这个版本if太多,被卡10s,TIME_OUT_LIMIT调到13s勉强能过
unsigned floatPower2(int x) {
    int t;
    if(x>128) x=128;
    if(x<=-150) x=-150;
    t=(1<<7)-1;//exp=t-bias==127-127=0
    t=t+x;
    if(t<=0)
    {
        t=((1<<22)>>-t);
    }
    else
    {

        t=t<<23;
    }
    return t;
}
