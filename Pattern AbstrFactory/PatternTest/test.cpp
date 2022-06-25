#include "pch.h"
#include "../Pattern AbstrFactory/Pattern AbstrFactory.h"

namespace labtest
{
  TEST(TestCaseName, DefoultConstrTest) {
    AbstractFactory* F = new ResidentialFactory();
    F = new NoResidentialFactory();

  }

  TEST(TestCaseName, GetTest) {


  }

  TEST(TestCaseName, ODZTest) {

  }

  TEST(TestCaseName, ODZTest) {

  }

  int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
}
