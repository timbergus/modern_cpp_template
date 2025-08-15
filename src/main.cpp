#include <cstdlib>
#include <print>

#include "my_lib.h"

int main(int, char **) {
  auto result = my_lib::take_half_if_even("6");

  if (result) {
    auto number = result.value();

    if (number) {
      std::println("Half of 4 is: {}", number.value());
    } else {
      std::println("The number is odd!");
    }
  } else {
    std::println("Error: {}", to_string(result.error()));
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
