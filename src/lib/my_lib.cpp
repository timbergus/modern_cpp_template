#include <expected>
#include <optional>
#include <print>
#include <string>

#include "my_lib.h"

/**
 * @brief Takes half of an even number represented as a string.
 * @param number The string representation of the number.
 * @return The half of the number if it's even, or an error if it's odd.
 */
std::expected<std::optional<int>, my_lib::Error>
my_lib::take_half_if_even(std::string_view num) {
  try {
    int number = std::stoi(num.data(), nullptr, 10);

    if (number % 2 == 0) {
      return number / 2;
    } else {
      return std::nullopt;
    }
  } catch (...) {
    return std::unexpected(my_lib::Error::InvalidInput);
  }
}
