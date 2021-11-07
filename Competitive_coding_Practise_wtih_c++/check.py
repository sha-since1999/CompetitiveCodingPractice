def is_palindrome(name):
    i = 0
    j = len(name)-1
    name = name.lower()
    while(i < j):
        if(name[i] != name[j]):
            return False
        i += 1
        j -= 1
    return True


def count_vowel(name):
    vowel = ['a', 'e', 'i', 'o', 'u']
    count_vowel = 0
    name = name.lower()
    for letter in name:
        if(letter in vowel):
            count_vowel += 1
    return count_vowel


def count_frequency(name):
    name = name.lower()
    dict = {}
    for letter in name:
        if letter not in dict:
            dict[letter] = 0
        dict[letter] += 1
    return dict
