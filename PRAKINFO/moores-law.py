#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov 14 14:20:14 2023

@author: lesi9952
"""
import matplotlib.pyplot as plt


class Processor:
    def __init__(self, name, transistors, year):
        self.name = name
        self.transistors = transistors
        self.year = year
    def __str__(self):
        return f"Processor(name = {self.name}, transistors = {self.transistors}, year = {self.year})"
    
f = open("transistor-counts.csv", "r")
processorsList = []
lines = f.readlines()
for line in lines:
    line = line.split(',')
    if line[0] == "#processor":
        continue
    name, transistor, year, manufacturer, proces, area = line
    proc = Processor(name, int(transistor), int(year))
    processorsList.append(proc)
    
plt.scatter([proc.year for proc in processorsList], [proc.transistors for proc in processorsList])
plt.yscale("log")
plt.ylabel("Tranzistoriu skaicius")
plt.xlabel("Isleidimo metai")
plt.title("Muro desnis")
plt.show()
