from __future__ import division
from fractions import gcd
from collections import defaultdict
t=input()
dic=defaultdict(int);
dic_index={};
dic1=defaultdict(int);
for i in range(1,t+1):
	a,b,c=map(int,raw_input().split())
	if(a==0 and  b!=0):
		dic1[(0,1)]+=1
	if(a!=0 and  b==0):
		dic1[(1,0)]+=1;
	if a != 0 and b != 0:
		d=gcd(abs(a),abs(b))
		a=a//d
		b=b//d
	tp=(a,b)
	dic_index[i]=tp
	dic[tp]+=1
q=input()
while q:
	qq=0
	qq=input()
	a=dic_index[qq][0]
	b=dic_index[qq][1]
	if a==0 and b==0:
		print '0'
		q-=1
		continue
	if a==0 and b!=0:
		count=0;
		count=dic1[(1,0)]
		print count
		q-=1
		continue
	elif a!=0 and b==0:
		count=0;
		count=dic1[(0,1)]
		print count
		q-=1
		continue
	else:
		print dic[(-b,a)]+dic[(b,-a)]
	q-=1