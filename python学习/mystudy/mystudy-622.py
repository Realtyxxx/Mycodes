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