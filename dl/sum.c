// see DL class in Ruby std lib
double sum(double *arry, int len)
  {
          double ret = 0;
          int i;
          for(i = 0; i < len; i++){
                  ret = ret + arry[i];
          }
          return ret;
  }

  double split(double num)
  {
          double ret = 0;
          ret = num / 2;
          return ret;
  }
