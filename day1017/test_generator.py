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
		print "number done"
