puts 'hello' > 'as'

require 'byebug'

def quick_sort(array, first, last)
  if first < last
    j = partition(array, first, last)

    quick_sort(array, first, j-1)
    quick_sort(array, j+1, last)
  end

  return array
end

def partition(array, first, last)
  pivot   = array[last]
  pIndex  = first
  i       = first

  while i < last
    print array
    print "\n"
    if array[i].to_i <= pivot.to_i
      array[i], array[pIndex] = array[pIndex], array[i]
      pIndex += 1
    end
    i += 1
  end

  array[pIndex], array[last] = array[last], array[pIndex]

  return pIndex
end 

array = [67, 5, 99, 3, 21, 39, 44, 11, 15, 23, 56]
        [5, 67, 99, 3, 21, 39, 44, 11, 15, 23, 56]
        [5, 67, 99, 3, 21, 39, 44, 11, 15, 23, 56]
        [5, 3, 99, 67, 21, 39, 44, 11, 15, 23, 56]
# index [ 0, 1, 2,  3,  4,  5,  6,  7,  8,  9, 10]

# print array
# print "\n"
result = quick_sort(array, 0, array.count - 1)
# puts result