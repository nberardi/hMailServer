// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "Math.h"
#include <Math.h>

namespace HM
{
   Math::Math()
   {

   }

   Math::~Math()
   {

   }

   float 
   Math::Round(const float &number, const int num_digits)
   {
      float doComplete5i, doComplete5(number * powf(10.0f, (float) (num_digits + 1)));

      if(number < 0.0f)
         doComplete5 -= 5.0f;
      else
         doComplete5 += 5.0f;

      doComplete5 /= 10.0f;
      modff(doComplete5, &doComplete5i);

      return doComplete5i / powf(10.0f, (float) num_digits);
   }
}