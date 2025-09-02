#include "catch2/catch_test_macros.hpp"
#include "my_ho_lib.h"
#include <cstdlib>

TEST_CASE("congratulate function works", "[my_ho_lib]") {
  std::string response =
      fmt::format(fg(fmt::color::chartreuse) | fmt::emphasis::bold,
                  "Congrats USER for making it this far!");
  REQUIRE(my_ho_lib::congratulate("USER") == response);
}
