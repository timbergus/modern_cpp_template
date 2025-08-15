#pragma once

#include <expected>
#include <optional>
#include <string_view>

/**
 * @namespace my_lib
 * @brief A example library to demonstrate C++ features.
 */
namespace my_lib {
enum Error { InvalidInput };

std::expected<std::optional<int>, my_lib::Error>
take_half_if_even(std::string_view number);
} // namespace my_lib

/**
 * @brief Converts an error code to a string representation.
 * @param error The error code to convert.
 * @return A string representation of the error.
 */
constexpr std::string_view to_string(my_lib::Error e) {
  switch (e) {
  case my_lib::Error::InvalidInput:
    return "Invalid input";
  }
  return "Unknown error";
}
