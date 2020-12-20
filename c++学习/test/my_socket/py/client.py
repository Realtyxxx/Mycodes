# -*- encoding=utf-8 -*-

import socket

def client():
		#创建套接字
		s = socket.socket()
		#连接套接字
		s.connect(('localhost',6666))
		print('Recv msg: %s, Client: %d' %(s.recv(1024),i))
		s.close()
if __name__ == '__main__':
		for i in range(10):
				client()