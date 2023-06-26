#pragma once

namespace sample {

struct HelloWorld 
{
  template<class OsTy>
  friend OsTy& operator<<(OsTy& os, const HelloWorld&) 
  {
    os << "Hello World!";
    return os;
  }
};

}
