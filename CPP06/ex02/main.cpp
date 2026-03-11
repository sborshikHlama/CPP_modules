#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  int random = rand() % 3;
  if (random == 0) {
    return new A();
  } else if (random == 1) {
    return new B();
  } else {
    return new C();
  }
}

void identify(Base *p) {
  if (!p)
    return;

  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Unknown type" << std::endl;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  } catch (std::exception &e) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    } catch (std::exception &e) {
      try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
      } catch (std::exception &e) {
        std::cout << "Unknown type" << std::endl;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  //   Base* ptr = new B();
  //   A* a = static_cast<A*>(ptr);
  // a->someMethodOfA();

  Base *ptr = generate();
  Base &ref = *ptr;

  std::cout << "Identify by pointer: ";
  identify(ptr);

  std::cout << "Identify by reference: ";
  identify(ref);

  delete ptr;

  return 0;
}
