#include <cstdlib>
#include <print>

#include "my_ho_lib.h"
#include "my_lib.h"

int main(int, char **) {
  std::string input = "6";

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

  my_ho_lib::congratulate();

  return EXIT_SUCCESS;
}
