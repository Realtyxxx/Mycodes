print('-'*30+'对象：')
class student(object):
    def __init__(self,name,score):
        self.name=name
        self.score=score
    def print_score(self):
        print('{} : {}'.format(self.name,self.score))
bart=student('Bart Simpson',59)
lisa=student('Lisa Simpson',87)

bart.print_score()
lisa.print_score()
print('-'*35)
import time
class Role:
    def __init__(self,name,hp):
        self.name=name
        self.hp=hp
        pass
    def tong(self,enemy):
        enemy.hp-=10
        info='{}捅了{}一刀'.format(self.name,enemy.name)
        print(info)
        pass
    def kanren(self,enemy):
        enemy.hp-=15
        info='{}砍了{}一刀'.format(self.name,enemy.name)
        print(info)
        pass
    def chiyao(self):
        self.hp+=10
        info='{}吃了一颗补血药 增加10滴血'.format(self.name)
        print(info)
        pass
    def __str__(self):
        return '{}还剩{}的血量'.format(self.name,self.hp)
    
xmcx=Role('西门吹雪',100)
ygc=Role('叶孤城',100)
while True:
    if xmcx.hp<=0 or ygc.hp<=0:
        break
    xmcx.kanren(ygc)
    print(ygc)
    print(xmcx)
    print('*'*30)
    ygc.tong(xmcx)
    print(ygc)
    print(xmcx)
    print('*'*30)
    xmcx.chiyao()
    print(ygc) 
    print(xmcx)
    time.sleep(3)
    pass
print('game is over')


