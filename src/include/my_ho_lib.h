#pragma once

#include <fmt/base.h>
#include <fmt/color.h>

/**
 * @namespace my_ho_lib
 * @brief A namespace for my custom header only library.
 */
namespace my_ho_lib {
/**
 * @brief Prints a congratulatory message.
 * @return  void
 */
inline void congratulate() {
  // Function implementation goes here
  fmt::print(fg(fmt::color::chartreuse) | fmt::emphasis::bold,
             "Congrats for making it this far!\n");
}
} // namespace my_ho_lib
