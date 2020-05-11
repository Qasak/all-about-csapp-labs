int isLessOrEqual(int x, int y) {
    /* x<=y
       <=> !(y<x) ,在(y+(-x))不溢出的情况下
       <=> !(y+(-x)<0)
       <=> !(((y+(~x+1))>>31)&1) 即:两数和为负则return 0,为正则return 1.
           溢出:两个参数彼此同号,其和与二者异号
           <=> ((!(((y>>31)&1)^(((~x+1)>>31)&1))) ^ (((y+(~x+1))>>31)&1))
            溢出的情况下:
            1) y,(-x)为正, 和溢出为负,此时一定有x<y成立 return 1
            2) y,(-x)为负, 和溢出为正,此时一定有x>y成立 return 0
            那么有真值表

                    是否溢出        和是否为负   返回值
            y+(-x)  0               0            1
                    0               1            0
                    1               0            0
                    1               1            1


       综上:
    */
    int sign_y=(y>>31)&1;
    int sign_m_x=((~x+1)>>31)&1;
    int sign_sum=((y+(~x+1))>>31)&1;
    int of_flag=((!(sign_y^sign_m_x))&sign_y)^(sign_sum);
    return (!(of_flag^sign_sum));
}