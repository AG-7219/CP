s=input("")
flag=0
for i in range(0,len(s),2):
  if(s[i].isupper()):
    flag=1
    break
    
if(flag==0):
  for i in range(1,len(s),2):
    if(s[i].islower()):
      flag=1
      break
      
if(flag):
  print("No")
else:
  print("Yes")