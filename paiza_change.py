# coding: utf-8


def get_reversed(s):
    if s == "b":
        return "w"
    elif s == "w":
        return "b"
    else:
        raise KeyError


def find_index_of_first(arr, first):
    l = len(arr)
    for i in range(1, l):
        if arr[-i] == first:
            return l - i

    return False


def find_index_of_last(arr, last):
    return arr.index(last)


# first => b or w
def update(arr, first):
    index_first = find_index_of_first(arr, first)
    index_last = find_index_of_last(arr, get_reversed(first))
    if index_last == index_first + 1:
        return "".join(arr)

    else:
        inside = [get_reversed(c) for c in arr[index_last:index_first + 1]]
        new_arr = list(arr)
        new_arr[index_last:index_first+1] = inside
        return update(new_arr, first)


if __name__ == "__main__":

    N = int(input())
    line = list(input())
    first = line[0]
    last = line[-1]
    if first == last and first == "b":
        print(N)
    elif first == last:
        print(0)
    else:
        last = update(line, first)
        print(last.count("b"))
