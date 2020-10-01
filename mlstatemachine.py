rn = 2018101039
axe = 0.60
action=["right","left","left"]
obs=["red","green","green"]
pr=[[0.9,0.15],[0.1,0.85]]		# redpr=[0.9,0.15]
								# greenpr=[0.1,0.85]
p=[1/3,1/3,0,0,1/3]
with open("2018101039.txt",'w+') as f:
	f.write(str(rn)+'\n')
	f.write(str(axe)+" 0"+'\n')
	

	for a in range(3):
		print()
		p1=[]
		if action[a]=="left":
			x=1-axe
		else:
			x=axe

		for i in range(5):
			k=0
			if(i==0):
				k=p[0]*(1-x)+p[1]*(1-x)
			elif(i==4):
				k=p[4]*x+p[3]*x
			else:
				k=p[i-1]*x+p[i+1]*(1-x)
			p1.append(k)

		print([round(s,3) for s in p1])
		red=p1[0]+p1[1]+p1[4]
		green=p1[2]+p1[3]
		print("red"+str(round(red,3)))
		print("green"+str(round(green,3)))
		t=1
		if obs[a]=="red":t=0
		k = red*pr[t][0]+green*pr[t][1]
		print("k--"+str(round(k,3)))
		fr= red*pr[t][0]/k
		fg= green*pr[t][1]/k
		print(round(fr,3),end=" ")
		print(round(fg,3))

		for i in range(5):
			if(i==2 or i==3):
				p1[i]=(p1[i]*fg)/green
			else:
				p1[i]=(p1[i]*fr)/red

		for i in p1:
			f.write(str(round(i,3))+" ")
		f.write("\n")
		
		print([round(s,3) for s in p1])
		

		p=p1

	f.close()