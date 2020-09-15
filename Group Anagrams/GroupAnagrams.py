#
# Created on Mon Sep 14 2020
#
# Copyright (c) 2020 SaiReddy
#


def groupAnagrams(words):
    anagrams_group = {}
    for word in words:
        word_sorted = "".join(sorted(word))
        if word_sorted not in anagrams_group:
            anagrams_group[word_sorted] = list()
        anagrams_group[word_sorted].append(word)
    print(list(anagrams_group.values()))


words = ["abc", "dabd", "bca", "cab", "ddba"]

groupAnagrams(words)

words = ["cinema", "a", "flop", "iceman", "meacyne", "lofp", "olfp"]
groupAnagrams(words)
