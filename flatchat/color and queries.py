from math import *
def back_track(x,y,d):
	xdir=[0,1,-1,0]
    ydir=[1,0,0,-1]
    if matrix[x][y]==1:
    	return
    matrix[x][y]=1
    for i in range(4):
    	xx=x+xdir[i]
    	yy=y+ydir[i]
    	if xx<0 or xx>=n or yy<0 or yy>=m:
    		pass
    	elif abs(l[xx][yy]-l[x][y])<=d and matrix[xx][yy]==0:
    		back_track(xx,yy,d)
     
n,m,q=map(int,raw_input().split())
l=[map(int,raw_input().split()) for i in range(n)]
     
while q:
	result=0
    x,y,d=map(int,raw_input().split())
    matrix= [[0 for j in range(m)] for i in range(n)]
    back_track(x-1,y-1,d)
    for i in range(n):
    	for j in range(m):
    		if matrix[i][j]==1:
    			result+=1
     
    print result
    q-=1
     


