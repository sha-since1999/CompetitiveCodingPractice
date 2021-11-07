from check import *
name = "ramamar"
if(is_palindrome(name)):
    print("yes it is palindrome")
else:
    print("No it is not palindrome")

    
vowel_count= count_vowel(name)
print("No of vowel : {}".format(vowel_count))

letter_freq=count_frequency(name)
print("frequency of letters: ")
for key , value in letter_freq.items():
    print('{}-{}'.format(key, value))
    
