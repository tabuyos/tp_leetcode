cmake_minimum_required(VERSION 3.19)
project(tp_leetcode C)

set(CMAKE_C_STANDARD 11)

add_executable(tp_leetcode main.c)
add_executable(two_sum src/com/tabuyos/leetcode/two_sum.c)
add_executable(add_two_numbers src/com/tabuyos/leetcode/add_two_numbers.c)
add_executable(longest_substring_without_repeating_characters src/com/tabuyos/leetcode/longest_substring_without_repeating_characters.c)
add_executable(median_of_two_sorted_arrays src/com/tabuyos/leetcode/median_of_two_sorted_arrays.c)
add_executable(longest_palindromic_substring src/com/tabuyos/leetcode/longest_palindromic_substring.c)
add_executable(zigzag_conversion src/com/tabuyos/leetcode/zigzag_conversion.c)