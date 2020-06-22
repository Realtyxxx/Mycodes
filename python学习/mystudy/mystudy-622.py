#coding=UTF-8
ls=[n**2 for n in range(10)]
print(ls)
planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']

print('-'*40)
for planet in planets:
    print(planet, end=' ') # 在同一行显示全部行星的名字，以空格做间隔
print()

#Git: warning: Pulling without specifying how to reconcile divergent branches is
s = 'steganograpHy is the practicE of conceaLing a fiLe, message, image, Or video Within anOtheR fiLe, message, image, or viDeo.'

# 打印上方一段话里的大写字母

for char in s:
    if char.isupper():
        print(char, end='')  
print()
print('-'*40)

short_planets = [planet for planet in planets if len(planet) < 6]
print(short_planets)
print('-'*40)
my_planets=[planet.upper()+'!' for planet in planets if planet.__len__()<6]
print(my_planets)

print('-'*40)
print([32 for planet in planets])
print('-'*40)

planet = 'Pluto'
claim='Pluto is a planet'
print(claim.startswith(planet))
words=claim.split()
print(words)
print('-'*40)

datestr='2020-6-22'
year,month,day=datestr.split('-')
print(year)
print(month)
print(day)
print('-'*40)
print('😁'.join([month,day,year]))
print('-'*40)
position = 9
print(planet + ", you'll always be the " + str(position) + "th planet to me.")
print('{0}, you\'ll always be the {1}th planet to me.'.format(planet,position))
print('-'*40)
pluto_mass = 1.303 * (10**22)
earth_mass = 5.9722 * (10**24)
population = 52910390

print("{} weighs about {:.2} kilograms ({:.3%} of Earth's mass). It is home to {:,} Plutonians.".format(planet, pluto_mass, pluto_mass / earth_mass, population,))
print('-'*40)
print('-'*40)

print('-'*40)

import math

print("It's math! It has type {}".format(type(math)))
print(dir(math))
print(math.pi)
print("pi to 4 significant digits = {:.4}".format(math.pi))
print(math.log(32,2))
# help(math)

from math import log,pi
from numpy import asarray
print(log(32,2))
import numpy

print("numpy.random is a", type(numpy.random))
print("it contains names such as...",dir(numpy.random)[-25:-20])
print('-'*40)
import numpy
rolls = numpy.random.randint(low=1, high=6, size=10)

print(rolls)
print(type(rolls))