from cs50 import get_int


def main():
    n = get_height()
    print_blocks(n)


def get_height():
    while True:
        n = get_int("Height: ")
        if n < 9 and n > 0:
            return n


def print_blocks(size):
    space = size - 1
    hashtag = 1

    while hashtag <= size:
        print(" " * space + "#" * hashtag + " " * 2 + "#" * hashtag)
        hashtag += 1
        space = space - 1


main()
