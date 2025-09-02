#pragma once

#include <fmt/base.h>
#include <fmt/color.h>

/**
 * @namespace my_ho_lib
 * @brief A namespace for my custom header only library.
 */
namespace my_ho_lib {
/**
 * @brief Prints a title.
 * @return  void
 */
inline void title(std::string_view title) {
  fmt::print(fg(fmt::color::chartreuse) | fmt::emphasis::bold, "{}\n", title);
}

/**
 * @brief Prints a congratulatory message.
 * @return  void
 */
inline std::string congratulate(std::string_view name) {
  return fmt::format(fg(fmt::color::chartreuse) | fmt::emphasis::bold,
                     "Congrats {} for making it this far!", name);
}
} // namespace my_ho_lib
