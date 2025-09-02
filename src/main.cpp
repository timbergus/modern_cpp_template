#include <cnmea/cnmea.h>
#include <cstdlib>
#include <print>

#include "fmt/base.h"
#include "my_ho_lib.h"
#include "my_lib.h"

int main(int, char **) {
  my_ho_lib::title("This is a NMEA sample");

  auto sample =
      cnmea::parse("$GNGLL,3150.788156,N,11711.922383,E,062735.00,A,A*76");

  cnmea::print(sample.value());

  std::string input = "6";

  my_ho_lib::title("And this tests one of the libraries");
  auto result = my_lib::take_half_if_even(input);

  if (result) {
    auto number = result.value();

    if (number) {
      std::println("Half of {} is {} 😄", input, number.value());
    } else {
      std::println("The number is odd!");
    }
  } else {
    std::println("Error: {}", to_string(result.error()));
    return EXIT_FAILURE;
  }

  fmt::println("{}", my_ho_lib::congratulate("USER"));

  return EXIT_SUCCESS;
}
