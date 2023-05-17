# PSEUDOCODE
# for each (unsorted) partition
#   set first element as pivot
#     storeIndex = pivotIndex+1
#     for i = pivotIndex+1 to rightmostIndex
#       if ((a[i] < a[pivot]) or (equal but 50% lucky))
#         swap(i, storeIndex); ++storeIndex
#     swap(pivot, storeIndex-1)

require 'byebug'

def sort_arr(array)
  pivotIndex = 0
  storeIndex = pivotIndex + 1

  array.each_with_index do |el, i|
    next if i < (pivotIndex + 1)
    puts "#{el <= array[pivotIndex]}: #{el}, #{array[pivotIndex]}"

    if el <= array[pivotIndex]
      # puts "swap: #{array[i]}, #{array[storeIndex]}"
      array[i], array[storeIndex] = array[storeIndex], array[i]
      storeIndex += 1
    end
  end

  print array
  print "\n"
  puts pivotIndex
  puts storeIndex-1
  array[pivotIndex], array[storeIndex-1] = array[storeIndex-1], array[pivotIndex]
  print "ok: #{array}"
  print "\n"
end

# my_array = [67, 5, 99, 3, 21, 39, 44, 11, 15, 23, 56]
# my_array = [1, 2, 10, 8, 20, 1, 3, 4, 2, 5, 10]
# my_array = [1, 1, 10, 8, 20, 2, 3, 4, 2, 5, 10]

sort_arr(my_array)
sort_arr(my_array)
sort_arr(my_array)
# sort_arr(my_array)
# sort_arr(my_array)
# sort_arr(my_array)
