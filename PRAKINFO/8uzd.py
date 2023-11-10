#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov  1 18:46:31 2023

@author: lesi9952
"""
import collections

longestWord = ""
symbols = [',', '.', '!', '?', ':', ';', '–', '/', '„', '“', '-', '(', ')', '[', ']', '\n', '\\', '=']
f = open("Metai.txt", "r", encoding="utf8")

wholeText = f.read()

for symbol in symbols:
    wholeText = wholeText.replace(symbol, '')

onlyWords = wholeText.split()
onlyWords = [word.lower() for word in onlyWords]

for word in onlyWords:
    if word.isalpha():
        if len(word) > len(longestWord):
            longestWord = word

print("Ilgiausias rastas zodis:")
print(longestWord)
print("Apskaiciuotas zodziu skaicius:",len(onlyWords))
onlyWords = collections.Counter(onlyWords)
print(onlyWords)
