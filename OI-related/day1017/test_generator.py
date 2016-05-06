#coding=utf-8
import sys
print "todo list",sys.argv[1:]
for i in sys.argv[1:]:
	if(i=="number"):
		import random
		f=open("number.in","w")
		n=random.randint(1,50)
		k=random.randint(0,n)
		s=random.randint(0,int(0.5*(n-k+1+n)*k))
		f.write("%d %d %d\n"%(n,k,s))
		f.close()
		print "%s done"%i
	elif(i=="circle"):
		import random
		f=open("circle.in","w")
		n=random.randint(1,300000)
		f.write("%d\n"%n)
		for j in range(n):
			x=random.randint(-999999999,999999999)
			r=random.randint(1,1000000000-abs(x))
			f.write("%d %d\n"%(x,r))
		f.close()
		print "%s done"%i
	elif(i=="wander"):
		f=open("wander.in","w")
		f.write("我不喜欢wander...")
		f.close()
		print "%s done"%i